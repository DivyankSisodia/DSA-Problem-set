class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                cnt++;
            }
            
            if(cnt == k){
                break;
            }
            ans = ans + s[i];
        }
        return ans;
    }
};