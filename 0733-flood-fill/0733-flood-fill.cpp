class Solution {
public:
    
    void dfs(vector<vector<int>>&ans, vector<vector<int>>& image, int row, int col, int color, int delrow[], int delcol[], int inicolor){
        
        ans[row][col] = color;
        
        int n = ans.size();
        int m = ans[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color){
                dfs(ans,image,nrow,ncol,color,delrow,delcol,inicolor);
            }   
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> ans = image;
        
        int inicolor = image[sr][sc];
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        dfs(ans, image, sr, sc, color, delrow, delcol ,inicolor);
        
        return ans;
    }
};