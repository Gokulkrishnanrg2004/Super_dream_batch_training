class Solution {
public:
    long long coloredCells(int n) 
    {
        long long result;
        //nquare + 2pow n-2
        result = 2LL * n * (n-1) + 1;
        return result;
    }
};