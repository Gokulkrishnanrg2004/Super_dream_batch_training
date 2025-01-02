class MinStack {
private:
    stack<pair<int,int>>st;
public:
    MinStack() {}
    
    void push(int val) 
    {
        if(st.empty())
        {
            st.push({val,val});
        }    
        else 
        {
            int currentmin = st.top().second;   
            st.push({val,min(currentmin,val)});
        }
    }
    
    void pop() 
    {
        if(!st.empty())
        {
            st.pop();
        }    
    }
    
    int top() 
    {
        return st.top().first;    
    }
    
    int getMin() 
    {
        return st.top().second;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */