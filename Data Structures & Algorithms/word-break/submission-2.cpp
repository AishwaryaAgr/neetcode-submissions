class Solution {
public:
    map<int, bool > memo;
    bool solve( string s, map<char, vector<string> > mp, int i){
        int n = s.size();
        if(i==n) return true;
        bool a = false;
        if(mp.find(s[i]) == mp.end()) return a;
        if(memo.find(i)!=memo.end()) return memo[i];
        for(string st: mp[s[i]]){
            int m = st.size();
            if(i+m>n+1) continue;
            string temp = s.substr(i,m);
            if(temp == st){
                a = a || solve(s,mp,i+m);
            }
        }
        memo[i] = a;
        return a;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        map<char, vector<string> > mp;
        for(string str : wordDict){
            if(mp.find(str[0]) == mp.end()){
                mp[str[0]] = {};
            }
            mp[str[0]].push_back(str);
        }
        return solve(s,mp,0);
    }
};
