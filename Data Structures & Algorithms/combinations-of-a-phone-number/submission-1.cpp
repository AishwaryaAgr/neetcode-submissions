class Solution {
public:
    vector<string> combine(vector<string> ff,vector<string> ss){
        vector<string> ans;
        for(string f:ff){
            for(string s:ss){
                ans.push_back(f+s);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return {};
        vector<string> ans;
        switch(digits[0]){
            case '2':
                ans = {"a","b","c"};
                break;
            case '3':
                ans = {"d","e","f"};
                break;
            case '4':
                ans = {"g","h","i"};
                break;
            case '5':
                ans = {"j","k","l"};
                break;
            case '6':
                ans = {"m","n","o"};
                break;
            case '7':
                ans = {"p","q","r","s"};
                break;
            case '8':
                ans = {"t","u","v"};
                break;
            case '9':
                ans = {"w","x","y","z"};
                break;
                
        }
        for(int i=1;i<n;i++){
            string t = "";
            t+=digits[i];
            vector<string> temp = letterCombinations(t);
            ans = combine(ans,temp);
        }
        return ans;
    }
};
