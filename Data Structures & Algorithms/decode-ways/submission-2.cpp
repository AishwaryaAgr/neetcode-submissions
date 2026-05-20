class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), f=1,se=1;
        if(s[0] == '0') return 0;
        for(int i=1;i<n;i++){
            int a = 0;
            if(s[i] != '0'){
                a+=se;
            }
            int in = 10*(s[i-1]-'0')+s[i]-'0';
            if(in && in<27 && s[i-1] != '0'){
                a+=f;
            }
            if(a==0) return 0;
            f=se;
            se=a;
        }
        return se;
    }
};
