class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int t, vector<int>& nums) {
        priority_queue<int> temp;
        pq=temp;
        k=t;
        for(int num : nums){
            pq.push(0-num);
        }
    }
    
    int add(int val) {
        pq.push(0-val);
        while(pq.size() > k){
            pq.pop();
        }
        if(pq.size() == k) return 0-pq.top();
        return -1;
    }
};
