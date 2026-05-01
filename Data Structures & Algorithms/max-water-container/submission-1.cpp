class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        int low = 0, high = n-1;
        while(low<high){
            int vol = min(h[low],h[high])*(high - low);
            ans = max(ans, vol);
            if(h[high] > h[low]){
                low++;
            }
            else high--;
        }
        return ans;
    }
};
