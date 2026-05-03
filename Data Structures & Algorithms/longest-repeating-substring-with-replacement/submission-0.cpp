class Solution {
public:
    int findMax(unordered_map<char, int> mp){
        int ans = 0;
        for(auto it:mp){
            ans = max(ans, it.second);
        }
        return ans;

    }
    
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int ans = 1, window = 1, i=1,j=0;
        mp[s[0]]=1;
        while(i<s.size()){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]=0;
            }
            mp[s[i]]++;
            int mxcount = findMax(mp);
            int curr = window + 1 - mxcount;
            if(curr <= k){
                window++;
                ans = max(ans,window);
                i++;
            }else{
                mp[s[j++]]--;
                window--;
                mp[s[i]]--;
            }
        }
        return ans;

    }
};
