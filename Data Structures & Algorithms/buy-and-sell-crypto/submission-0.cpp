class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), big = prices[n-1], ans = 0 ;
        for(int i=n-2;i>=0;i--){
            ans = max(ans, big - prices[i]);
            big = max(big, prices[i]);
        }
        return ans;
    }
};
