class TimeMap {
public:
    map<string, vector<pair<int,string>> > mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if(mp.find(key) == mp.end()) mp[key] = {};
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int time) {
        if(mp.find(key) == mp.end()) return "";
        vector<pair<int,string> > sol = mp[key];
        if(sol[0].first > time) return "";
        int n = sol.size();
        if(sol[n-1].first <= time) return sol[n-1].second;
        int s = 0, e=n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(sol[mid].first == time){
                return sol[mid].second;
            }
            if(sol[mid].first < time && sol[mid+1].first > time){
                return sol[mid].second;
            }
            if(sol[mid].first > time){
                e = mid-1;
            }else{
                s=mid+1;
            }
        }
        return "";
    }
};
