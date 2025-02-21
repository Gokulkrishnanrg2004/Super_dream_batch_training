class Solution {
    public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string>mp;
        vector<string>result;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if(digits.size()==0)
        {
            return result;
        }
        else 
        {
            result = getAllComb(digits,mp);
        }
        return result;
    }
    vector<string>getAllComb(const string& digits,const unordered_map<char,string>& mp)
    {
        if(digits.empty())
        {
            return {""};
        }

        char ch = digits[0];
        string s = digits.substr(1);

        vector<string>res = getAllComb(s,mp);
        // vector<string>arr;
        vector<string>mres;
        string digit_str = mp.at(ch);
        for(char ch : digit_str)
        {
            for(string s : res)
            {
                mres.push_back(ch+s);
            }
        }
        return mres;
    }
};