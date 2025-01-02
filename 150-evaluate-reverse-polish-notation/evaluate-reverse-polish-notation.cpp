class Solution {
    public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>st;
        for(const string& token : tokens)
        {
            if(isOperator(token))
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(calculate(a,b,token));
            }
            else 
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
    private:
    bool isOperator(const string& token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    int calculate(int a,int b,const string& token)
    {
        if(token == "+") 
            return a+b;
        if(token == "-")
            return a-b;
        if(token == "*")
            return a*b;
        if(token == "/")
            return a/b;
        return 0;
    }
};