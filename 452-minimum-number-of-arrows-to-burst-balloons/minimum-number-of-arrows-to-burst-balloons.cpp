class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b)
        {
            return a[1] < b[1];
        });
        int arrows = 1;
        int arrowpos = points[0][1];//to shoot at the end of the 1st baloon

        for(int i=1;i<points.size();i++)
        {
            if(arrowpos < points[i][0])
            {
                arrows++;
                arrowpos = points[i][1];
            }
        }
        return arrows;
    }
};