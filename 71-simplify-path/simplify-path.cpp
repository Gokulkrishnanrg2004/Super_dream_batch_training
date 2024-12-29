class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string component;
        stack<string>st;
        while(getline(ss,component,'/'))
        {
            if(component=="" || component==".")
            {
                continue;
            }
            else if(component=="..")
            {
                if(!st.empty())
                    st.pop();
            }
            else 
            {
                st.push(component);
            }
        }   
        string result = "/";
        while(!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        } 
        return result=="/" ? result : result.substr(0,result.size()-1);
    }
};