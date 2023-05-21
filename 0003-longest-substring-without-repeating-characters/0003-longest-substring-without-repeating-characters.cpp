class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         map<char,int> mp;
//         int length = 0;
//         int maxLen = 0;
//         int j = 0;
        
//         for(int i=0; i<s.size(); i++){
//             mp[s[i]]++;
//             length++;
//             while(mp[s[i]] > 1){
//                 mp[s[j]]--;
//                 j++;
//                 length--;
//             }
//             maxLen = max(maxLen,length);
//         }
//         return maxLen;
        
        int i=0;
        int j=0;
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        
        while(j<n){
            mp[s[j]]++;
            
            // waise yeh condn kbhi hit kregi hi nhi
            if(mp.size() > j-i+1){
                j++;
            }
            
            
            if(mp.size() == j-i+1){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};