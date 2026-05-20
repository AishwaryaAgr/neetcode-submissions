class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt >= n-1) return true;
            if(cnt < i) return false;
            cnt = max(cnt, i+nums[i]);
            cout << cnt << endl;
        }
        return (cnt >=n-1);
    }
};
