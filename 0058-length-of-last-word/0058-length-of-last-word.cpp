class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int cnt = 0;
        bool isCounting = false;
        for(int i=n-1; i>=0; i--){
            if(s[i] != ' '){
                cnt++;
                isCounting = true;
            }
            else if(isCounting){
                break;
            }
        }
        return cnt;
    }
};