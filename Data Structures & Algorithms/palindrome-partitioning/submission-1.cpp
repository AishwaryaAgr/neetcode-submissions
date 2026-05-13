class Solution {
public:
    bool isPal(string s){
        int n = s.size();
        if(n==1) return true;
        int i = 0 , j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        if(n==0) return {{}};
        if(n==1) return {{s}};
        map<string, vector<vector<string>> > mp;
        vector<vector<string> > ans;
        string start = s,end = "";
        int i = n;
        while(i>0){
            cout << start << " " << end << endl;
            if(isPal(start)){
                vector<vector<string>> sec ;
                if(mp.find(end) != mp.end()){
                    sec = mp[end];
                }
                else{
                    sec = partition(end);
                    mp[end] = sec;
                }
                for(auto v : sec){
                    // v.push_back(start);
                    v.insert(v.begin(), start);
                    ans.push_back(v);
                }
            }
            end = s[i-1] + end;
            start.pop_back();
            i--;
        }
        return ans;

    }
};
