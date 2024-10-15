class Solution {
public:
    void reverse(vector<int>& arr,int l,int r)
    {
        while(l<=r)
        {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        // vector<int>ans;
        // int n = nums.size();
        // for(int i=n-k;i<n;i++)
        // {
        //     ans.push_back(nums[i]);
        // }
        // for(int i=0;i<n-k;i++)
        // {
        //     ans.push_back(nums[i]);
        // }
        // for(int i=0;i<ans.size();i++)
        // {
        //     nums[i] = ans[i];
        // }
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};