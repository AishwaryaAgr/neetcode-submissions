class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<pair<int,int> > st;
        int ans = h[0];
        st.push(make_pair(h[0],0));
        for(int i=1;i<n;i++){
            int pos = i;
            while(st.size() && st.top().first>h[i]){
                int len = st.top().first;
                int ind = st.top().second;
                int curr = len*(i-ind);
                ans = max(curr,ans);
                pos = min(pos,ind);
                st.pop();
            }
            st.push(make_pair(h[i],pos));
        }
        while(st.size()){
            ans = max(ans,st.top().first*(n-st.top().second));
            st.pop();
        }

        return ans;
    }
};
