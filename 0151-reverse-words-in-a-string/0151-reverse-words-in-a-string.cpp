class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i=0;
        int n = s.size();
        
        while(i<n){
            if(s[i] == ' '){
                i++;
            }
            else{
                string temp = "";
                while(i<n && s[i] != ' '){
                    temp = temp + s[i];
                    i++;
                }
//              inserting the first word in ans
                if(ans.size() == 0){
                    ans = temp;
                }
                else{
                    ans = temp + ' ' + ans;
                }
            }
        }
        return ans;
    }
};