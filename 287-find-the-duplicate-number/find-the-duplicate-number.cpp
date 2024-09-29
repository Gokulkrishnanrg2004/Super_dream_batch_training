class Solution {
public:
    int findDuplicate(vector<int>& nums) 
{
    // Step 1: Initialize two pointers for cycle detection
    int slow = nums[0];
    int fast = nums[0];

    // Step 2: Move the pointers until they meet inside the cycle
    do {
        slow = nums[slow];         // move slow by 1 step
        fast = nums[nums[fast]];   // move fast by 2 steps
    } while (slow != fast);

    // Step 3: Reset one pointer to the start and move both by 1 step until they meet again
    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];  // move both by 1 step
        fast = nums[fast];
    }

    // Step 4: Return the duplicate number
    return slow;
}

};