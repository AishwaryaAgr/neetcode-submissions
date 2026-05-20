class Solution {
public:
    map<pair<int,int>,bool > mp;

    bool solve(vector<int>& nums, int target, int start){
        int n = nums.size();
        if(target == 0) return true;
        if(n==start) return false;
        if(mp.find(make_pair(target,start))!= mp.end()) return mp[make_pair(target,start)];
        bool x = solve(nums,target-nums[start],start+1) || solve(nums,target, start+1);
        mp[make_pair(target,start)] = x;
        return x;
    }

    bool canPartition(vector<int>& nums) {
        mp.clear();
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum+=num;
        if(sum%2) return false;
        int target = sum/2;
        return solve(nums,target,0);
    }
};
