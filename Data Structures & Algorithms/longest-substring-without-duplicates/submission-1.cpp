class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, ref=-1,count=0;
        for(int i =0 ;i<s.size();i++){
            char a = s[i];
            if(mp.find(a) == mp.end()){
                count++;
            }else{
                ref = max(ref, mp[a]);
                count = i - ref;
            }
            ans = max(ans,count);
            mp[a]=i;
        }
        return ans;
    }
};
