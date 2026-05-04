class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<pair<int,int> > st;
        int ans = h[0];
        st.push(make_pair(h[0],1));
        for(int i=1;i<n;i++){
            stack<pair<int,int> > temp;
            if(h[i]>h[i-1]){
                ans = max(h[i],ans);
                temp.push(make_pair(h[i],1));
            }
            while(st.size()){
                int a = st.top().first, b= st.top().second;
                int last = a/b;
                b++;
                int val  = min(h[i],last)*b;
                temp.push(make_pair(val,b));
                ans = max(ans, val);
                st.pop();
            }
            st = temp;
        }
        return ans;
    }
};
