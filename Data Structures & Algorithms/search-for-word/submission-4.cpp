class Solution {
public:
    bool solve(vector<vector<char>> board, int x,int y, string word, int wi){
        int n = word.size();
        cout << word[wi] << " " << wi << " ; ";
        if(wi == n-1) return true;
        char next = word[wi+1];
        board[x][y] = '.';
        bool z = false;
        if(x-1>=0 && board[x-1][y] == next){
            z = z || solve(board,x-1,y,word,wi+1);
        }if(x+1 < board.size() && board[x+1][y] == next){
            z = z || solve(board,x+1,y,word,wi+1);
        }if(y-1>=0 && board[x][y-1] == next){
            z = z || solve(board,x,y-1,word,wi+1);
        }if(y+1< board[0].size() && board[x][y+1] == next){
            z = z || solve(board,x,y+1,word,wi+1);
        }
        return z;
    }
    bool exist(vector<vector<char>>& board, string word) {
        char start = word[0];
        int n =board.size(),m = board[0].size();
        bool x = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == start){
                    x = x || solve(board,i,j,word,0);
                }
            }
        }
        return x;
    }
};
