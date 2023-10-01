class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int last = -1;
        
        for(int i=0; i<=n; i++){
            if(i == n || s[i] == ' '){
                int start = last + 1;
                int end = i-1;
                while(start < end){
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }
                last = i;
            }
        }
        return s;
    }
};