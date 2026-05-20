class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0],final = nums[0];
        int ans = max(0,nums[0]);
        for(int i=1;i<nums.size();i++){
            ans = max(0,ans+nums[i]);
            mx = max(mx,nums[i]);
            final = max(ans,final);
        }
        if(mx<0) return mx;
        return final;
    }
};
