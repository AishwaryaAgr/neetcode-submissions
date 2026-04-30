class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums){
            if(mp.find(num) == mp.end()){
                mp[num]=0;
            }
            mp[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp ){
            pq.push(make_pair(it.second,it.first));
        }
        int count = 0,last =0;
        vector<int> ans;
        while(k--){
            int curr = pq.top().second;
            pq.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};
