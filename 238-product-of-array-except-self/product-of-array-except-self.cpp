class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans;
        vector<int>a(n,1); // Inittialize the array a with 1's
        for(int i=1;i<n;i++)
        {
            a[i] = a[i-1]*nums[i-1]; // 1 1 2 6
        }    
        vector<int>b(n,1);
        for(int i=n-2;i>=0;i--)
        {
            b[i] = b[i+1]*nums[i+1]; // 24 12 4 1
        }
        for(int i=0;i<n;i++)
        {
            int prod = a[i]*b[i]; // 24 12 8 6
            ans.push_back(prod);
        }
        return ans;
    }
};