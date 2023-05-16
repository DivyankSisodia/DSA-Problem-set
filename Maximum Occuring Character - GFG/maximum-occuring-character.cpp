//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string s)
    {
        // Your code here
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int maxi = 0;
        char ch;
        for(auto it: mp){
            if(maxi < it.second){
                ch = it.first;
                maxi = it.second;
            }
        }
        return ch;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends