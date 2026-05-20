class Solution {
public:
    int rob(vector<int>& nums) {
        int f = 0, s = 0,n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            int a = max(f+nums[i],s);
            f=s;
            s=a;
        }
        int ans = max(f,s);

        f=0;s=0;
        for(int i=1;i<n;i++){
            int a = max(f+nums[i],s);
            f=s;
            s=a;
        }

        ans = max(ans,s);
        return ans;
    }
};
