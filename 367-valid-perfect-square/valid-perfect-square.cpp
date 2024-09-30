class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1)
        {
            return true;
        }   
        for(int i=2;i<=num;i++)
        {
            if((long long)i*i>num)
            {
                return false;
            }
            if((long long)i*i==num)
            {
                return true;
            }
        }
        return false;
    }
};