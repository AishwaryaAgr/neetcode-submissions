class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ref(n,-1);
        for(int i=n-2;i>=0;i--){
            if(temp[i]>=temp[i+1]){
                int t=temp[i+1],m=i+1;
                while(m>=0 && t<=temp[i]){
                    if(ref[m]==-1){
                        m=-1;
                        break;
                    }
                    else{
                        t= temp[ref[m]];
                        m=ref[m];
                    }
                }
                
                ref[i] = m;
            }else{
                ref[i] = i+1;
            }
        }
        for(int i=0;i<n;i++){
            if(ref[i]>-1){
                ref[i]-=i;
            }else{
                ref[i]=0;
            }
        }
        return ref;
    }
};
