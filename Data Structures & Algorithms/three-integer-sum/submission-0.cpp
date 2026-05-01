class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums,int start, int target){
        int n = nums.size();
        vector<vector<int>> ans;
        if(n-start < 2) return {};
        int low = start, high = n-1;
        while(low<high){
            int sum = nums[low] + nums[high];
            if(sum == target){
                int l =nums[low], h = nums[high];
                ans.push_back({0-target, l,h});
                while(l == nums[low] && low <n){
                    low++;
                }
                high--;
            }
            else if(sum<target) low++;
            else high --;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last = 1;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]== last) continue;
            last = nums[i];
            vector<vector<int>> temp = twoSum(nums, i+1,0-last);
            for(vector<int> arr : temp){
                ans.push_back(arr);
            }
            
        }
        return ans;
    }
};
