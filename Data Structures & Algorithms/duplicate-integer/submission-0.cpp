class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            if(mp.find(num) == mp.end()) mp[num] = 1;
            else return true;
        }
        return false;
    }
};