//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int dp[201][201];
    bool isAllStars(string & S1, int i) {
        for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
        }
        return true;
    }
    int solve(string s, string t, int i, int j){
         if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
            return isAllStars(s, i);
            
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j] || s[i] == '?'){
            return dp[i][j]=solve(s,t,i-1,j-1) ;
        }
        else{
            if(s[i] == '*'){
                return dp[i][j] = solve(s,t,i-1,j) || solve(s,t,i,j-1);
            }
            else{
                return 0;
            }
        }
        
    }
    int wildCard(string s,string t)
    {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,n-1,m-1);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends