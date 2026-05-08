class Solution {
public:
    void solve(vector<int> nums, int start, vector<int> curr, vector<vector<int> > &ans){
        if(start == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[start]);
        solve(nums,start+1,curr,ans);
        curr.pop_back();
        solve(nums,start+1,curr,ans);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> curr;
        solve(nums,0,curr,ans);
        return ans;
    }
};
