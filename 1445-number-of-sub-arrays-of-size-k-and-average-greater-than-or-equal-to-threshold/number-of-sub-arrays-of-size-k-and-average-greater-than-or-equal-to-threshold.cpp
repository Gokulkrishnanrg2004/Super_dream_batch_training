class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int left = 0;
        int n = arr.size();
        int sum = 0,count=0;
        for(int right = 0;right<n;right++)
        {
            sum += arr[right];
            if(right - left + 1 == k)
            {
                int avg = sum/k;
                if(avg >= threshold)
                {
                    count++;
                }
                sum -= arr[left];
                left++;
            }
        }    
        return count;
    }
};