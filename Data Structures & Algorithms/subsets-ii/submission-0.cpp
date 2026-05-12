class Solution {
public:
    void solve(vector<int> temp, int start, vector<int> nums, vector<vector<int> > &ans){
        int n = nums.size();
        if(start >= n){
            ans.push_back(temp);
            return;
        } 
        ans.push_back(temp);
        for(int i=start;i<n;i++){
            temp.push_back(nums[i]);
            solve(temp,i+1,nums,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int> > removeDupes(vector<vector<int> > ans){
        vector<vector<int> > solution;
        int i = 1,j=0;
        for(int x=0;x<ans.size();x++){
            sort(ans[x].begin(),ans[x].end());
        }
        sort(ans.begin(),ans.end());
        solution.push_back(ans[0]);
        while(i<ans.size()){
            if(solution[j] == ans[i]){
                i++;
            }else{
                solution.push_back(ans[i]);
                j++;
            }
        }
        return solution;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp = {};
        solve(temp,0,nums,ans);
        return removeDupes(ans);
    }
};
