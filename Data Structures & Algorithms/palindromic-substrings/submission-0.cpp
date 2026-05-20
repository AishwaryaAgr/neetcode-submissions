class Solution {
public:
    int countSubstrings(string str) {
        int n = str.size();
        int ans = 0,i=0;
        while(i<n){
            int s= i,e=i;
            while(s>=0 && e<n){
                if(str[s] == str[e]){
                    ans++;
                    s--;
                    e++;
                }else break;
            }
            i++;
        }
        i=0;
        while(i<n-1){
            int s= i,e=i+1;
            while(s>=0 && e<n){
                if(str[s] == str[e]){
                    ans++;
                    s--;
                    e++;
                }else break;
            }
            i++;
        }
        return ans;
    }
};
