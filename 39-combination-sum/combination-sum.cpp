class Solution {
public:
void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            // If the target is zero, we found a valid combination
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Skip if the current candidate exceeds the remaining target
            if (candidates[i] > target) break;

            // Include the current candidate and explore further
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);  // 'i' allows repetition of the same element
            current.pop_back();  // Backtrack: remove the last element
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the candidates to improve efficiency by breaking early on larger values
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;  
    }
};