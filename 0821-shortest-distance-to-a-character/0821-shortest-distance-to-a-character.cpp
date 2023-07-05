class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), INT_MAX);
        int z=INT_MAX;
        for(int i=0; i<s.size(); i++){
            if(s[i] == c){
                z = i;
            }
            ans[i]=min(ans[i],abs(i-z));
        }
        z=INT_MAX;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == c){
                z = i;
            }
            ans[i]=min(ans[i],abs(i-z));
        }
        
        
        return ans;
    }
};