class Solution {
public:
    long long dp[200001] = {{0}};
    long long solve(int i, vector<vector<int>>& v, int n){
        // v[i][0] means vector ke ith position pr joh [x,y] h uska 0th wala dedo
        if(i == n-1){
            return v[i][0];
        }
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != 0){
            return dp[i];
        }

        long long take = v[i][0] + solve(i+1+v[i][1],v,n);
        long long notTake = 0 + solve(i+1,v,n);

        return dp[i] = max(take,notTake);
        
    }
    
    long long mostPoints(vector<vector<int>>& v) {
        // memset(dp,-1,sizeof(dp));
        int n = v.size();
        return solve(0,v,n);
    }
};