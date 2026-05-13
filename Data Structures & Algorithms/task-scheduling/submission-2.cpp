class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for( auto t:tasks){
            cnt[t-'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int,int> > q;

        for(int c:cnt){
            if(c) pq.push(c);
        }
        int time = 1;
        while(pq.size() || q.size()){
            if(q.size() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.size()){
                if(pq.top()>1) q.push(make_pair(pq.top()-1,time+n+1));
                pq.pop();
            }
            time++;
        }
        return time-1;
    }
};
