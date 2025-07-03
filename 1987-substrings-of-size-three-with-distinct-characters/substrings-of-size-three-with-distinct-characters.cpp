class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int count = 0;
        int left = 0;
        int mid = 1;
        for(int right = 2;right < s.length();right++)
        {
            if(s[left] != s[mid] && s[mid] != s[right] && s[left] != s[right])
            {
                count++;
            }
            left++;
            mid++;
        }    
        return count;
    }
};