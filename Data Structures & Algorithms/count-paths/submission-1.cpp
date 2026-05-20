class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        bool flag = true;
        if(m>n) swap(m,n);
        for(int i=n,j=1;i<n+m-1;i++){
            ans*=i;
            ans/=j;
            if(flag && j<m){
                j++;
            }else{
                flag=false;
                j=1;
            }
        }
        
        return (int) ans;
    }
};
