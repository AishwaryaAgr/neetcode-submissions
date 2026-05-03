class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        q.push_back(nums[0]);
        for(int i=1;i<k;i++){
            int val = nums[i];
            while(q.size() && q.back() < val){
                q.pop_back();
            }
            q.push_back(val);
        }
        ans.push_back(q.front());
        for(int i=k;i<n;i++){
            int val = nums[i];
            if(q.front() == nums[i-k]){
                q.pop_front();
            }
            while(q.size() && q.back() < val){
                q.pop_back();
            }
            q.push_back(val);
            ans.push_back(q.front());
        }
        return ans;
    }
};
