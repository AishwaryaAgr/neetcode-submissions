class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1);

        for(int i =1;i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        int postfix = 1;
        for(int i=n-1;i>=0;i--){
            pre[i]*=postfix;
            postfix*=nums[i];
        }
        return pre;
    }
};
