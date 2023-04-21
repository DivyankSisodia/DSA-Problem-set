class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int length = 0;
        int maxLen = 0;
        int j = 0;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            length++;
            while(mp[s[i]] > 1){
                mp[s[j]]--;
                j++;
                length--;
            }
            maxLen = max(maxLen,length);
        }
        return maxLen;
    }
};