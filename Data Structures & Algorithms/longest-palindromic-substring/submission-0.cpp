class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size(), i=0,ansS = 0, ansE = 0,ans=0;
        while(i<n){
            int s = i, e=i,temp=0;
            while(s>=0 && e<n){
                if(str[s] == str[e]){
                    temp = e-s+1;
                }else{
                    break;
                }
                if(ans < temp){
                    ansS = s;
                    ansE = e;
                }
                ans = max(ans,temp);
                s--;
                e++;
            }
            
            i++;
        }
        i=0;
        while(i<n-1){
            int s=i,e=i+1,temp=0;
            while(s>=0 && e<n){
                if(str[s] == str[e]){
                    temp = e-s+1;
                }else{
                    break;
                }
                if(ans < temp){
                    ansS = s;
                    ansE = e;
                }
                ans = max(ans,temp);
                s--;
                e++;
            }
            i++;
        }
        cout << ansS;
        return str.substr(ansS,ans);
    }
};
