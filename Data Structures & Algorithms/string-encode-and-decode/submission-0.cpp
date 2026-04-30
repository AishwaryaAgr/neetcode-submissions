class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        string counts = "";
        for(int i=0;i<n;i++){
            counts+= to_string(strs[i].size());
            counts+='.';
        }
        ans += to_string(counts.size());
        ans+='.';
        ans+=counts;
        for(int i=0;i<n;i++){
            ans+= strs[i];
        }
        cout << ans;
        return ans;
    }

    vector<string> decode(string ans) {
        int n = 0;
        int start = 0;
        while(ans[start]!='.'){
            n*=10;
            n+= ans[start++] - '0';
        }
        string counts = ans.substr(start+1,n);
        vector<string> input;
        int itr = start+1+n;
        int x=0,m = counts.size();
        while(x<m){
            int tmp = 0;
            while(counts[x]!='.'){
                tmp*=10;
                tmp+= counts[x++] - '0';
            }
            string found = ans.substr(itr,tmp);
            x++;
            itr= itr+tmp;
            input.push_back(found);
        }
        return input;
    }
};
