class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int total = n*m;
        int sr = 0;
        int sc = 0;
        int er = n-1;
        int ec = m-1;
        int cnt = 0;
        vector<int> ans;
        
        while(cnt<total){
            for(int i=sc; i<=ec && cnt < total; i++){
                ans.push_back(v[sr][i]);
                cnt++;
            }
            sr++;
            
            for(int i=sr; i<=er && cnt < total; i++){
                ans.push_back(v[i][ec]);
                cnt++;
            }
            ec--;
            
            for(int i=ec; i>=sc && cnt < total; i--){
                ans.push_back(v[er][i]);
                cnt++;
            }
            er--;
            
            for(int i=er; i>=sr && cnt < total; i--){
                ans.push_back(v[i][sc]);
                cnt++;
            }
            sc++;
        }
        
        return ans;
    }
};