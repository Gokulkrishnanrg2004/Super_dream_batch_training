class Solution {
public:

    bool ifPossible(vector<int>& weights,int d,int w)
    {
        int days = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i]<=w)
            {
                sum += weights[i];
            }
            else 
            {
                days++;
                sum = weights[i];
            }
        }
        return days<=d;
    }
    int shipWithinDays(vector<int>& weights, int d) 
    {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(ifPossible(weights,d,mid))
            {
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        return low;
    }
};