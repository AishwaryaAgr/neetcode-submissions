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
            if(i>start && nums[i] == nums[i-1]) continue;
            curr+=nums[i];
            if(curr > target) break;
            v.push_back(nums[i]);
            solve(nums,curr,target,ans,v,i+1);
            curr-=nums[i];
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int curr = 0;
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans,final;
        vector<int> v;
        solve(nums,curr,target,ans,v,0);
        sort(ans.begin(),ans.end());
        vector<int> last = {-1};
        for(auto it: ans){
            if(it == last){
                continue;
            }
            final.push_back(it);
            last = it;
        }
        return final;
    }
};
