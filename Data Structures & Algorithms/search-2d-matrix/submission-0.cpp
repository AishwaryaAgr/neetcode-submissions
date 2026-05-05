class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int start = 0, end = m*n-1;
        while(start<=end){
            int mid = (start+end)/2;
            int x = mid/m;
            int y= mid%m;
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] < target){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};
