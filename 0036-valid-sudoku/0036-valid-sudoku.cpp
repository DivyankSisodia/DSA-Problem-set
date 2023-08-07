class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[9][9]={0},b[9][9]={0},c[9][9]={0};
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board.size();++j){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;
                    int k= i / 3 * 3 + j / 3;
                    if(a[i][num]||b[j][num]||c[k][num]){
                        return false;
                    }
                        a[i][num]=b[j][num]=c[k][num]=1;
                    
                }

            
            }

        }
        return true;
    }
};