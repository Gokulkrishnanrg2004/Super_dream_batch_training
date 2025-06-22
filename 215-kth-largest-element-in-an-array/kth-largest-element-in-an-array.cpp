class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>maxheap;
        for(int num : nums)
        {
            maxheap.push(num);
        }   
        int val; 
        while(k > 0)
        {
            val = maxheap.top();
            maxheap.pop();
            k--;
        }
        return val;
    }
};