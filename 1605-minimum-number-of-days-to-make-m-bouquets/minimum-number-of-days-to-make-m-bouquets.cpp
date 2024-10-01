class Solution {
public:
    bool possible(vector<int>& arr,int maxd,int m,int k)
    {
        int b=0,f=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=maxd)
            {
                f++;
            }
            else 
            {
                f=0;
            }
            if(f==k)
            {
                b++;
                f=0;
            }
        }
        if(b>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) 
    {
        if((long long)m*(long long)k>arr.size())
        {
            return -1;
        }
        int low = *min_element(arr.begin(),arr.end());    
        int high = *max_element(arr.begin(),arr.end());
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(arr,mid,m,k))
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