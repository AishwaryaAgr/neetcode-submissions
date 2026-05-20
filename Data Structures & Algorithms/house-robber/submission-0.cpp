class Solution {
public:
    int rob(vector<int>& nums) {
        int f = 0, s = 0;
        for(int num : nums){
            int a = max(f+num,s);
            f=s;
            s=a;
        }
        return max(f,s);
    }
};
