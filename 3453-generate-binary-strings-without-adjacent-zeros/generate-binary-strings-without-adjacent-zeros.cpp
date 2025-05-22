class Solution 
{
    public:
    void generate(vector<string>&result,string arr,int n,int i)
    {
        if(arr.find("00") != string::npos)
        {
            return;
        }
        if(i == n)
        {
            result.push_back(arr);
            return;
        }

        arr.push_back('0');
        generate(result,arr,n,i+1);
        arr.pop_back();

        arr.push_back('1');
        generate(result,arr,n,i+1);
        arr.pop_back();
    }
    vector<string> validStrings(int n) 
    {
        vector<string>result;
        string arr = "";
        generate(result,arr,n,0);
        return result;
    }
};