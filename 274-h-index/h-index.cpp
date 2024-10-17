class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int hindex = 0;
        for(int i=0;i<n;i++)
        {
            //start from the highest citations
            int hcandidate = n - i;
            if(citations[i] >= hcandidate)
            {
                hindex = hcandidate;
                break;
            }
        }
        return hindex;
    }
};