class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt = 1;
        int sr = 0;
        int sc = 0;
        int er = n-1;
        int ec = n-1;
        
        while(sr<=er && sc<=ec){
            for(int i=sc; i<=ec; i++){
                ans[sr][i] = cnt++;
            }
            sr++;
            
            for(int i=sr; i<=er; i++){
                ans[i][ec] = cnt++;
            }
            ec--;
            
            for(int i=ec; i>=sc; i--){
                ans[er][i] = cnt++;
            }
            er--;
            
            for(int i=er; i>=sr; i--){
                ans[i][sc] = cnt++;
            }
            sc++;
        }
        return ans;
    }
};