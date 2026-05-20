class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n,1);
        for(int i=n-2;i>=0;i--){
            int r= 0;
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    r = max(r,dp[j]);
                }
            }
            dp[i] = 1+r;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
