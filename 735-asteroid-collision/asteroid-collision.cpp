class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>st;
        vector<int>ans;
        for(int ast : asteroids)
        {
            if(ast < 0 && !st.empty() && st.top() > 0)
            {
                bool flag = true;
                while(!st.empty() && st.top() > 0)
                {
                    if(abs(ast) > st.top())
                    {
                        st.pop();
                    }
                    else if(abs(ast) < st.top())
                    {
                        flag = false;
                        break;
                    }
                    else 
                    {
                        st.pop();
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    st.push(ast);
                }
            }
            else 
            {
                st.push(ast);
            }
        }    
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};