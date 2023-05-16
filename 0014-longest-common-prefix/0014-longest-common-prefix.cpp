class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(), s.end());
        string x = s[0];
        string y = s[s.size()-1];
        
        string ans = "";
        
        for(int i=0; i<x.size(); i++){
            if(x[i] == y[i]){
                ans.push_back(x[i]);
            }
            else{
                break;
            }
        }
        return ans;
    }
};