class MinStack {
public:
    stack<int> st;
    vector<int> mm;
    int n=0;
    int m=0; // The total length of the minimum vector
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(n!=0){
            val=min(val,mm[n-1]);
        }
        if(m==n) {
            mm.push_back(val);
            m+=1;
        }else
            mm[n]=val;
        n+=1;
    }

    void pop() {
        st.pop();
        n=n-1;        
    }

    int top() {
        return st.top();
    }
    
    int getMin() {
        return mm[n-1];
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