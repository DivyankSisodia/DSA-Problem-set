class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>> v = grid;
//         convert the rows into columns and columns into row. 
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(grid[i][j], grid[j][i]);
            }
        }
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                if(grid[i] == v[j]){
                    ans++;
                }
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};