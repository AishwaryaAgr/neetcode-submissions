class Solution {
public:
    void cleanpq(priority_queue<pair<int,int>> &pq){
        if(pq.top().second == -1){
            return;
        }
        int ones = 1;
        pq.pop();
        while(ones>0 || pq.top().second == 1){
            int act = pq.top().second;
            ones+=act;
            pq.pop();
        }
        return;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push(make_pair(nums[i],-1));
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        int start = 0;
        for(int i=k;i<nums.size();i++){
            pq.push(make_pair(nums[i],-1));
            pq.push(make_pair(nums[start++],1));
            cleanpq(pq);
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
