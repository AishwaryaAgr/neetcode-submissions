class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        for(int num : nums){
            if(mp.find(num) != mp.end()) continue;
            int before = 0, after = 0;
            if(mp.find(num+1)!=mp.end())  after = mp[num+1];
            if(mp.find(num-1)!=mp.end()) before = mp[num-1];
            int val = before+1+after;
            mp[num]=val;
            mp[num+after] = val;
            mp[num-before]=val;
            
            ans = max(ans,val);
        }
        return ans;
    }
};
