class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f(26,0), temp=f;
        for(char a : s){
            f[a-'a']++;
        }
        for(char b : t){
            f[b-'a']--;
        }
        return f == temp;
    }
};
