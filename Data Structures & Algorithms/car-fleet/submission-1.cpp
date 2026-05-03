class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        stack<double> time;
        int n = pos.size();
        vector<pair<int,int> > car(n);
        for(int i=0;i<n;i++){
            car[i] = make_pair(pos[i],speed[i]);
        }
        sort(car.begin(),car.end());
        for(int i = 0;i<n;i++){
            double tm = (target - car[i].first);
            tm/=car[i].second;
            cout<< tm << " ";
            while(time.size() && time.top()<=tm){
                time.pop();
            }
            time.push(tm);
        }
        return time.size();
    }
};
