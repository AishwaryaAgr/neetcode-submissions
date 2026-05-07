class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num:nums){
            pq.push(num);
            while(k < pq.size()){
                pq.pop();
            }
        }
        return pq.top();

    }
};
