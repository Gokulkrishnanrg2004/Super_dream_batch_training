class Solution {
    // public:
    // bool isVowel(char c)
    // {
    //     return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    // }
    // long long countOfSubstrings(string word, int k) 
    // {
        // int n = word.size();
        // unordered_set<char>vowels;
        // unordered_map<char,int>freq;
        // int left = 0;
        // int count = 0,consonants = 0;
        // for(int right = 0;right<n;right++)
        // {
        //     char c = word[right];
        //     freq[c]++;

        //     if(isVowel(c))
        //     {
        //         vowels.insert(c);
        //     }
        //     else 
        //     {
        //         consonants++;
        //     }
        //     while(consonants > k)
        //     {
        //         char leftchar = word[left];
        //         freq[leftchar]--;
        //         if(freq[leftchar] == 0)
        //         {
        //             vowels.erase(leftchar);
        //         }
        //         if(!isVowel(leftchar))
        //         {
        //             consonants--;
        //         }
        //         left++;
        //     }
        //     if(vowels.size()==5 && consonants == k)
        //     {
        //         count+= (left+1);
        //     }
        // }
        // return count;
    //     int n = word.length(), count = 0;
    // unordered_set<char> vowels; // Track unique vowels in the substring
    // unordered_map<char, int> freq; // Track character frequency
    // int left = 0, consonants = 0;
    
    // for (int right = 0; right < n; right++) {
    //     char c = word[right];
    //     freq[c]++;
        
    //     if (isVowel(c)) {
    //         vowels.insert(c);
    //     } else {
    //         consonants++;
    //     }
        
    //     while (consonants > k) { // Shrink window if consonants exceed k
    //         char leftChar = word[left];
    //         freq[leftChar]--;
    //         if (freq[leftChar] == 0) {
    //             vowels.erase(leftChar);
    //         }
    //         if (!isVowel(leftChar)) {
    //             consonants--;
    //         }
    //         left++;
    //     }
        
    //     if (vowels.size() == 5 && consonants == k) {
    //         count+=(n-right);
    //     }
    // }
    
    // return count;
    // }
    public:
    long long atMostK(string word, int k) {
        int n = word.size(), l = 0, cons = 0;
        long long atleastk = 0;
        map<char, int> vowels;

        // Step 1: Store all the vowels
        set<char> allvows = {'a', 'e', 'i', 'o', 'u'};
         
        for (int i = 0; i < n; i++) {

            // Step 2: Check whether word[i] is a vowel or consonant
            if (allvows.find(word[i]) != allvows.end())
                vowels[word[i]]++;
            else
                cons++;

            /* Step 3: We keep reducing the string from the left when we find 
             a substr with aeiou and atleast k consonants to the point where we have
             atleast aeiou and barely k consonants*/
            while (vowels.size() == 5 && cons > k) {
                if (allvows.find(word[l]) != allvows.end()) {
                    vowels[word[l]]--;
                    if (vowels[word[l]] == 0)
                        vowels.erase(word[l]);
                } else
                    cons--;
                l++;
            }
            
            // Step 4: The number of atleast k substr's at this index is i - l + 1
            atleastk += (i - l + 1);
        }
        return atleastk;
    }
    long long countOfSubstrings(string word, int k) {
        return atMostK(word, k) - atMostK(word, k - 1);
    }
};