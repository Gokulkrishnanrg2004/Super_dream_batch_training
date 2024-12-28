class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size()) return false;

        //Method 1
        // unordered_map<char,int>Map1;    
        // unordered_map<char,int>Map2;    

        // for(char c : s)
        // {
        //     Map1[c]++;
        // }
        // for(char c : t)
        // {
        //     Map2[c]++;
        // }
        // for(int i=0;i<s.size();i++)
        // {
        //     char c = s[i];
        //     if(Map1[c] != Map2[c])
        //     {
        //         return false;
        //     }
        // }
        // return true;

        //Method 2
        unordered_map<char,int>Map;
        for(int i=0;i<s.size();i++)
        {
            Map[s[i]]++;
            Map[t[i]]--;
        }
        for(auto it : Map)
        {
            if(it.second != 0)
                return false;
        }
        return true;
    }
};