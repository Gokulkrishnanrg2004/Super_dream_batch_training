class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        vector<string>words;
        stringstream ss(s);
        string word;

        while(ss >> word)
        {
            words.push_back(word);
        }    
        if(!words.empty())
        {
            return words.back().length();
        }
        return 0;
    }
};