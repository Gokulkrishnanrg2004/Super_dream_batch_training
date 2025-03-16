class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int minrank = ranks[0],maxrank = ranks[0];
        for(int rank : ranks)
        {
            minrank = min(minrank,rank);
            maxrank = max(maxrank,rank);
        }    
        vector<int>freq(maxrank+1);
        for(int rank : ranks)
        {
            minrank = min(minrank,rank);
            freq[rank]++;
        }
        long long low = 1, high = 1LL*minrank*cars*cars;
        while(low < high)
        {
            long long mid = (low+high)/2;
            long long carsrep = 0;

            for(int rank = 1;rank <= maxrank;rank++)
            {
                carsrep += freq[rank] * (long long)sqrt(mid / (long long)rank);
            }
            if(carsrep >= cars)
            {
                high = mid;
            }
            else 
            {
                low = mid+1;
            }
        }
        return low;
    }
};