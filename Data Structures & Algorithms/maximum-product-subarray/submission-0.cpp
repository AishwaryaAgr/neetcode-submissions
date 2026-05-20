class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n,0),neg(n,0);
        int ans = nums[0];
        if(nums[0] >= 0){
            pos[0] = nums[0];
        }else{
            neg[0] = 0-nums[0];
        }
        for(int i=1;i<n;i++){
            if(nums[i] == 0){
                pos[i] = 0;
                neg[i] = 0;
            }else if(nums[i]>0){
                pos[i] = max(nums[i],nums[i]*pos[i-1]);
                neg[i] = neg[i-1]*nums[i];
            }else{
                int num = 0-nums[i];
                pos[i] = num*neg[i-1];
                neg[i] = (pos[i-1]) ? pos[i-1]*num : num;
            }
            ans = max(ans,pos[i]);
        }
        return ans;
    }
};
