class MinStack {
public:
    stack<pair<int,int>> st;
    int currMin;
    MinStack() {
        
        stack<pair<int,int>> Tst;
        st=Tst;
        currMin = INT_MAX;
    }
    
    void push(int val) {
        st.push(make_pair(val,currMin));
        currMin = min(currMin,val);
    }
    
    void pop() {
        currMin = st.top().second;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return currMin;
    }
};
