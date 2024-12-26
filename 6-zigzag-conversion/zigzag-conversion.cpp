class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1) return s;
        
        vector<string>arr(numRows);
        int cur=0;
        bool godown = false;

        for(int i=0;i<s.length();i++)
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
        string result="";
        for(string s : arr)
        {
            result += s;
        }
        return result;
    }
};