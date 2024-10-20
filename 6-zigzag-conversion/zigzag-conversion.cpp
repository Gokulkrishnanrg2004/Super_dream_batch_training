class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1) return s;

        vector<string>arr(numRows);

        int cur = 0;
        bool godown = false;

        for(int i=0;i<s.size();i++)
        {
            arr[cur] += s[i];
            if(cur == 0 || cur == numRows - 1)
            {
                godown = !godown;
            }
            if(godown)
            {
                cur++;
            }
            else
            {
                cur--;
            }
        }
        string res = "";
        for(const string& row : arr)
        {
            res += row;
        }
        return res;
    }
};