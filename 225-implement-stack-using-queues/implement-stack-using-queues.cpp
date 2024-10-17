class MyStack 
{
    queue<int>q1,temp;
public:
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        if(q1.empty())
        {
            q1.push(x);
            return;
        }
        while(!q1.empty())
        {
            temp.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!temp.empty())
        {
            q1.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() 
    {
        if(!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            return x;
        }
        return -1;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
       return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */