class Solution {
public:
    
    bool isValid(vector<vector<char>> &board, int n, int row, int col, char c){
        for(int i=0; i<n; i++){
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
        }
        
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        
        for(int i=srow; i<srow+3; i++){
            for(int j=scol; j<scol+3; j++){
                if(board[i][j] == c){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudokuHelper(vector<vector<char>>& board, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(isValid(board,n, i, j, ch)){
                            board[i][j] = ch;
                            if(sudokuHelper(board,n) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        sudokuHelper(board,n);
    }
};