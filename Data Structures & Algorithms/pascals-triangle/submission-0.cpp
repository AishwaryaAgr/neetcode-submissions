class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int> >ans = {{1},{1,1}};
    
        for(int j=2;j<numRows;j++){
            vector<int> temp;
            temp.push_back(1);
            for(int i=0;i<ans[j-1].size()-1;i++){
                temp.push_back(ans[j-1][i]+ans[j-1][i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};