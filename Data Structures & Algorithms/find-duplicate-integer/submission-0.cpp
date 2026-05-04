class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int val = nums[i]%n;
            if(nums[val]>n) return val;
            nums[val]+=n;
        }
        return -1;
    }
};
