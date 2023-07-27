class Solution {
public:
    
    void solve(int n, int open, int close, string ans, vector<string> &res){
        if(open == 0 && close == 0){
            res.push_back(ans);
            return;
        }
        
        if(open != 0){
            string x = ans;
            x.push_back('(');
            solve(n, open-1, close, x, res);
        }
        
        if(close > open){
            string y = ans;
            y.push_back(')');
            solve(n, open, close-1, y, res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string ans = "";
        int open = n;
        int close = n;
        vector<string> res; 
        
        solve(n,open,close,ans,res);
        
        return res;
    }
};