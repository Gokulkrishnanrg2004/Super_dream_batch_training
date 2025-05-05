class Solution {
public:
    int numTilings(int n) 
    {
        const int MOD = 1e9 + 7;

        if(n==1) return 1;    
        if(n==2) return 2;    
        if(n==3) return 5;

        long long a = 1;    
        long long b = 2;    
        long long c = 5;
        long long d;

        for (int i = 4; i <= n; ++i) 
        {
            d = (2 * c % MOD + a) % MOD;
            a = b;
            b = c;
            c = d;
        }    
        return c;
    }
};