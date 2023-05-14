class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        int i=0;
        int j=0;
        
        string ans = "";
        
        while(i<n && j<m){
            ans.push_back(s1[i]);
            ans.push_back(s2[j]);
            i++;
            j++;
        }
        while(i<n){
            ans.push_back(s1[i]);
            i++;
        }
        
        while(j<m){
            ans.push_back(s2[j]);
            j++;
        }
        return ans;
    }
};