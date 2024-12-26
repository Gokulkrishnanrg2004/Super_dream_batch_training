class Solution {
public:
    int strStr(string a, string b) 
    {
        if(a==b)
            return 0;
        int l1 = a.length();
        int l2 = b.length();
        int count=0,flag=0,index=0;
        for(int i=0;i<=l1-l2;i++)
        {
            count=0;
            for(int j=0;j<l2;j++)
            {
                if(a[i+j]==b[j])
                {
                    count++;
                }
            }
            if(count==l2)
            {
                flag=1;
                index = i;
                break;
            }
        }
        return (flag==1) ? index : -1;
    }
};