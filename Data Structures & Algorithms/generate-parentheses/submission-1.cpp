class Solution {
public:
    void solve(int sum, set<string> &ans, string curr,int n){
        if(sum<0 || sum > n){
            return;
        }
        if(curr.size() == 2*n){
            if(sum == 0) ans.insert(curr);
            return;
        }
        solve(sum+1,ans,curr+"(",n);
        solve(sum-1,ans,curr+")",n);
        return;
    }
    vector<string> generateParenthesis(int n) {
        set<string> ans;
        string curr = "";
        solve(0,ans,curr,n);
        vector<string> final;
        for(auto it: ans){
            final.push_back(it);
        }
        return final;
    }
};
