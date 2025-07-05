class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int low = 0, high = n - 1;
        int currentSum = 0;

        for (int i = 0; i < k; i++) 
        {
            currentSum += cardPoints[i];
        }

        int maxSum = currentSum;
        for (int i = 0; i < k; i++) 
        {
            currentSum -= cardPoints[k - i - 1]; 
            currentSum += cardPoints[high - i]; 
            maxSum = max(maxSum, currentSum);   
        }

        return maxSum;
    }
};
