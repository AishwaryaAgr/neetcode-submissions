class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> wt;
        for(int s:stones){
            wt.push(s);
        }
        while(wt.size()){
            if(wt.size() == 1) return wt.top();
            int x = wt.top();
            wt.pop();
            int y=wt.top();
            wt.pop();
            if(x==y){
                continue;
            }else{
                wt.push(x-y);
            }
        }
        return 0;
    }
};
