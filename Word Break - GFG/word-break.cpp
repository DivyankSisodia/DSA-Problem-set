//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    // int solve(int i, string s, set<string> &st){
    //     if(i == st.size()){
    //         return 1;
    //     }
        
    //     string temp;
        
    //     for(int j=i; j<s.size(); j++){
    //         temp = temp + s[j];
    //         if(st.find(temp) != st.end()){
    //             if(solve(j+1, s, st) == true){
    //                 return 1;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    int solve(int i, string s, set<string> &st){
        if(i == s.size()){
            return 1;
        }
        
        // if(dp[i] != -1){
        //     return dp[i];
        // }
        
        string temp;
        
        for(int j=i; j<s.size(); j++){
            temp = temp + s[j];
            if(st.find(temp) != st.end()){
                if(solve(j+1, s, st) == true){
                    return 1;
                }
            }
        }
        return 0;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        set<string> st;
        
        for(auto it: B){
            st.insert(it);
        }
        
        return solve(0, A, st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends