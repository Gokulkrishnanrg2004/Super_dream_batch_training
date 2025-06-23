class Solution 
{
    public:
    bool findsuccessor(vector<int>& hand,int groupsize,int i)
    {
        int next = hand[i] + 1;
        hand[i] = -1;
        i += 1;
        int count = 1;

        while(i< hand.size() && count < groupsize)
        {
            if(hand[i] == next)
            {
                next = hand[i]+1;
                hand[i] = -1;
                count++;
            }
            i++;
        }
        return count == groupsize;
    }
    bool isNStraightHand(vector<int>& hand, int groupsize) 
    {
        int n = hand.size();
        if(n%groupsize != 0) return false;
        sort(hand.begin(),hand.end());

        for(int i=0;i<n;i++)
        {
            if(hand[i] >= 0)
            {
                if(!findsuccessor(hand,groupsize,i)) return false;
            }
        }    
        return true;
    }
};