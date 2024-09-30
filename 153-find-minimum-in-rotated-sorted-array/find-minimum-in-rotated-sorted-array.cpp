class Solution {
public:
    int findMin(vector<int>& a) 
    {
        int mini = INT_MAX;
        int low = 0;
        int high = a.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(a[low]<=a[mid])
            {
                if(a[low]<mini)
                {
                    mini = a[low];
                }
                low = mid+1;
            }
            else 
            {
                if(a[mid]<mini)
                {
                    mini = a[mid];
                }
                high = mid - 1;
            }
        }
        return mini;
    }
};