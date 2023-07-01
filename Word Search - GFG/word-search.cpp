//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool solve(vector<vector<char>>& grid, string word, int i, int j, int ws, int n, int m){
        if(word.size() == ws){
            return true;
        }
        if(i >=n || i<0 || j<0 || j>=m || grid[i][j] != word[ws]){
            return false;
        }
        
        char ch = grid[i][j];
        grid[i][j] = '@';
        
        bool up = solve(grid, word, i-1, j, ws+1, n, m);
        bool down = solve(grid, word, i+1, j, ws+1, n, m);
        bool left = solve(grid, word, i, j-1, ws+1, n, m);
        bool right = solve(grid, word, i, j+1, ws+1, n, m);
        
        grid[i][j] = ch;
        
        return up || down || right || left;
        
    }

    bool isWordExist(vector<vector<char>>& grid, string word) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(grid,word,i,j,0,n,m) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends