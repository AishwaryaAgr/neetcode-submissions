class Solution {
public:
    bool checkHorizontal(vector<char> row){
        vector<int> ref(9,0);
        for(char r : row){
            if(r == '.') continue;
            int i = r-'1';
            if(ref[i]) return false;
            ref[i]=1;
        }
        return true;
    }
    bool checkVertical(vector<vector<char>> board, int col){
        vector<int> ref(9,0);
        for(int i=0;i<9;i++){
            if(board[i][col] == '.') continue;
            int val = board[i][col] - '1';
            if(ref[val]) return false;
            ref[val]=1;
        }
        return true;
    }
    bool checkBlock(vector<vector<char>> board, int row, int col){
        vector<int> ref(9,0);
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j]=='.') continue;
                int val = board[row+i][col+j] - '1';
                if(ref[val]) return false;
                ref[val]=1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int ans = true;
        for(int i=0;i<9;i++){
            ans = ans && checkHorizontal(board[i]);
        }
        if(!ans) return false;
        for(int i=0;i<9;i++){
            ans = ans && checkVertical(board,i);
        }
        if(!ans) return false;
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                ans = ans && checkBlock(board,i,j);
            }
        }
        return ans;
    }
};
