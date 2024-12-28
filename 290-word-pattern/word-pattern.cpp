class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char,string>Map1;
        unordered_map<string,char>Map2;

        stringstream ss(s);
        vector<string> arr;
        string str;
        while(ss >> str)
        {
            arr.push_back(str);
        }    
        int l1 = pattern.size();
        int l2 = arr.size();
        if(l1 != l2) return false;

        for(int i=0;i<l1;i++)
        {
            char c = pattern[i];
            string s = arr[i];

            if(Map1.find(c) != Map1.end())
            {
                if(Map1[c] != s)
                {
                    return false;
                } 
            }
            else 
            {
                Map1[c] = s;
            }
            if(Map2.find(s) != Map2.end())
            {
                if(Map2[s] != c)
                {
                    return false;
                } 
            }
            else 
            {
                Map2[s] = c;
            }
        }
        return true;
    }
};