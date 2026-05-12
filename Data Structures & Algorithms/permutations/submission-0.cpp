class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return {nums};
        vector<int> temp;
        vector<vector<int> > ans;
        int last = nums[n-1], li = n-1;
        temp = nums;
        temp.pop_back();
        int ind = 0;
        while(li>=0){
            vector<vector<int> > curr = permute(temp);
            for(int i=0;i<curr.size();i++){
                curr[i].push_back(last);
                ans.push_back(curr[i]);
            }
            int slast = temp[ind];
            cout << slast << " - " << li  << " ";
            temp[ind++] = last;
            last = slast;
            li--;
        }
        return ans;
    }
};
