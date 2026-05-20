class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> ans(amount+1,LONG_MAX);
        ans[0]=0;
        int n = coins.size();
        for(int j=0;j<n;j++){
            for(int i=0;i<amount;i++){
                if(ans[i]!= LONG_MAX){
                    if(i+coins[j] > amount) break;
                    ans[i+coins[j]] = min(ans[i]+1,ans[i+coins[j]]);
                }
            }
        }
        return ans[amount] == INT_MAX ? -1 : (int)ans[amount];
    }
};
