class Solution {
public:
    bool isPalindrome(string s) 
    {
        string result;
        for(char c:s)
        {
            if(isalnum(c))
            {
                result += tolower(c);
            }
        }
        int n = result.length();
        int left = 0;
        int right = n-1;
        while(left<=right)
        {
            if(result[left]!=result[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
        // string og = result;
        // reverse(result.begin(),result.end());
        // if(og == result)
        // {
        //     return true;
        // }
        // else 
        // {
        //     return false;
        // }
    }
};