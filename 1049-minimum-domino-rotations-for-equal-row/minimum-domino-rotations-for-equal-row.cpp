class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int res = INT_MAX;
        int face[7] = {};

        for(int i=0;i<tops.size();i++)
        {
            face[tops[i]]++;
            if(tops[i] != bottoms[i]) face[bottoms[i]]++;
        }    
        for(int x = 1;x<=6;x++)
        {
            if(face[x] < tops.size()) continue;

            int maintaintop = 0, maintainbottom = 0;
            bool rotate = true;

            for(int i=0;i<tops.size();i++)
            {
                if(tops[i] != x && bottoms[i] != x)
                {
                    rotate = false;
                    break;
                }
                if(tops[i] != x) maintaintop++;
                if(bottoms[i] != x) maintainbottom++;
            }
            if(rotate)
            {
                res = min(res, min(maintaintop, maintainbottom));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};