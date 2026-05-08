class Solution {
public:
    void solve(vector<int> nums,int curr, int target, vector<vector<int> > &ans,vector<int> v,int start){
        if(curr == target){
            ans.push_back(v);
            return;
        }
        if(curr>target){
            return;
        }
        for(int i=start;i<nums.size();i++){
            curr+=nums[i];
            v.push_back(nums[i]);
            solve(nums,curr,target,ans,v,i);
            curr-=nums[i];
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int curr = 0;
        vector<vector<int> > ans;
        vector<int> v;
        solve(nums,curr,target,ans,v,0);
        return ans;
    }
};
