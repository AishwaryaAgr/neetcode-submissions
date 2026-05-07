class Solution {
public:
    double distance(vector<int> pt){
        return sqrt(pt[0]*pt[0]+pt[1]*pt[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int> > pq;

        for(int i=0;i<points.size();i++){
            pq.push(make_pair(distance(points[i]),i));
        }
        while(pq.size() > k){
            pq.pop();
        }
        vector<vector<int> > ans;
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
