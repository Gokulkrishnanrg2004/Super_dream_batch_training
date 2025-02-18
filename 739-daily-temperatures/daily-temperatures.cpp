class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int>st;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                int ind = st.top();
                st.pop();
                arr[ind] = i - ind;
            }
            st.push(i);
        }
        return arr;
    }
};