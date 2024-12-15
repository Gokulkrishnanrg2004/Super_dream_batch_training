class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int low = 0, high = n - 1;
        int currentSum = 0;

        // Step 1: Take the first k cards from the start (low)
        for (int i = 0; i < k; i++) {
            currentSum += cardPoints[i];
        }

        int maxSum = currentSum;

        // Step 2: Gradually replace cards from the front (low) with cards from the end (high)
        for (int i = 0; i < k; i++) {
            currentSum -= cardPoints[k - i - 1]; // Remove the last card from the front
            currentSum += cardPoints[high - i];  // Add the card from the end
            maxSum = max(maxSum, currentSum);    // Track the maximum sum
        }

        return maxSum;
    }
};
