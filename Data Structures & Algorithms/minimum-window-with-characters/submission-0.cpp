class Solution {
public:
    bool isValid(unordered_map<char,int> ms,unordered_map<char,int> mt){
        for(auto a:mt){
            if(ms.find(a.first) == ms.end()) return false;
            if(ms[a.first] < a.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> ms,mt;
        int ansS = -1, ansL = INT_MAX;
        for(char a:t){
            if(mt.find(a)== mt.end()) mt[a]=0;
            mt[a]++;
        }
        ms[s[0]]=1;
        int start=0;
        if(isValid(ms,mt)){
            ansS = start;
            ansL = 1;
        }
        for(int i=1;i<s.size();i++){
            if(ms.find(s[i]) == ms.end()) ms[s[i]]=0;
            ms[s[i]]++;
            while(isValid(ms,mt)){
                if(i-start+1 < ansL){
                    ansL = i-start+1;
                    ansS = start;
                }
                ms[s[start++]]--;
            }
        }
        if(ansS == -1) return "";
        string ans = s.substr(ansS, ansL);
        return ans;
    }
};
