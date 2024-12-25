class Solution {
public:
    // void reverse(vector<int>& arr,int l,int r)
    // {
    //     while(l<=r)
    //     {
    //         swap(arr[l],arr[r]);
    //         l++;
    //         r--;
    //     }
    // }
    void rotate(vector<int>& nums, int k) 
    {
        vector<int>ans;
        int n = nums.size();
        k = k%n;
        if(k==0 || n==0)
        {
            return;
        }
        for(int i=n-k;i<n;i++)
        {
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++)
        {
            ans.push_back(nums[i]);
        }
        for(int i=0;i<ans.size();i++)
        {
            nums[i] = ans[i];
        }
        // int n = nums.size();
        // k = k % n;
        // // [1,2,3,4,5,6,7] k = 3
        // reverse(nums,0,n-1); // 0 to n-1 it reverse the whole [7,6,5,4,3,2,1]
        // reverse(nums,0,k-1); // 0 to k-1 it reverse before the 3 index element [5,6,7,4,3,2,1] 
        // reverse(nums,k,n-1); // k to n-1 3rd index to last index [5,6,7,1,2,3,4]
    }
};