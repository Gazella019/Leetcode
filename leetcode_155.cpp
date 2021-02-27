



class MinStack {
public:
    
    stack<int> mn;
    stack<int> st;
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if(mn.size() == 0)
        	mn.push(x);
        else 
        	mn.push(min(mn.top(), x));
    }
    
    void pop() {
        if(st.size() == 0)
        	return;
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

