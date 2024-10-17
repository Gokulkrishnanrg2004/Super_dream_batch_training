class Solution {
public:
    bool isPossible(vector<int>&arr,int dist,int m)
    {
        int last = arr[0];
        int balls = 1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-last>=dist)
            {
                balls++;
                last = arr[i];
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& arr, int m) 
    {
        sort(arr.begin(),arr.end());
        int low = 1;
        int high = arr[arr.size()-1];
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(arr,mid,m))
            {
                low = mid + 1;
            }
            else 
            {
                high = mid - 1;
            }
        }
        return high;
    }
};