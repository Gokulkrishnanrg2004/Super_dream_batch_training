class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!= t.size()) return false;

        unordered_map<char,int>Maps;
        unordered_map<char,int>Mapt;
        for(int i=0;i<s.size();i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if(Maps.find(c1) != Maps.end())
            {
                if(Maps[c1] != c2)
                    return false;
            }
            else 
            {
                Maps[c1] = c2;
            }
            if(Mapt.find(c2) != Mapt.end())
            {
                if(Mapt[c2] != c1)
                    return false;
            }
            else 
            {
                Mapt[c2] = c1;
            }
        }
        return true;
    }
};