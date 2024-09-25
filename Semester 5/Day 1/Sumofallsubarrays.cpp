/*
Example array :
int arr[3] = {1,2,3}
output = 20
  */

class Solution {
  public:
    long long subarraySum(vector<int>& arr) 
    {
        long long total=0;
        long long mod = 1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            long long s = i+1;
            long long e = arr.size()-i;
            
            total = (total +(arr[i]*s*e))%mod;
        }
        return total;
    }
};
