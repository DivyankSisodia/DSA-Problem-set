//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
        // code here
        int sum = 0;
        int digit = 0;
        int temp = 0;
        while(sum != 1){
            N++;
            sum = N;
            for(int i=0; i<1000; i++){
                if(sum > 1){
                    temp = sum;
                    sum = 0;
                    while(temp!=0){
                        digit = temp%10;
                        sum = sum+(digit*digit);
                        temp = temp/10;
                    }
                }
                else{
                    return N;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends