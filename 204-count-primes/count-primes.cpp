class Solution {
public:
    
    int countPrimes(int n) 
    {
        vector<bool> prime(n, true);
        for (int p = 2; p * p < n; p++) 
        {
            if (prime[p] == true) 
            {
                for (int i = p * p; i < n; i += p)
                    prime[i] = false;
            }
        }
        int count=0;
        for (int p = 2; p <n; p++)
            if (prime[p])
                count++;

        return count;
    }
};