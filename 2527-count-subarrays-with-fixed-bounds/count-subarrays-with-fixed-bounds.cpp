// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) 
//     {
//         long long count = 0;
//         for(int i = 0;i< nums.size(); i++)
//         {
//             int mini = INT_MAX, maxi = INT_MIN;
//             for(int j = i;j<nums.size();j++)
//             {
//                 mini = min(mini,nums[j]);
//                 maxi = max(maxi,nums[j]);
//                 if(mini == minK && maxi == maxK) count++;
//             }
//         }    
//         return count;
//     }
// };
class Solution {
public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0, start = -1, mini = -1, maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;
            int valid = max(0L, min(mini, maxi) - start);
            count += valid;
        }
        return count;
    }
};