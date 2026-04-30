class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        ans+=to_string(n);
        ans+="?";
        for(string str : strs){
            int m = str.size();
            ans+=to_string(m);
            ans+="/";
            ans+=str;
        }
        cout << ans;
        return ans;
    }

    vector<string> decode(string s) {
        int n = 0, i;
        for(i=0 ;i< s.size();i++){
            if(s[i]=='?') break;
            n*=10;
            n+= s[i]-'0';
        }
        i++;
        cout << n << " ";
        vector<string> ans;
        for(int j = 0;j<n;j++){
            int m = 0;
            while(s[i]!='/'){
                m*=10;
                m+= s[i++]-'0';
            }
            i++;
            string temp = "";
            while(m--){
                temp += s[i++];
            }
            cout << temp << " ";
            ans.push_back(temp);
        }
        return ans;
    }
};
