class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int ans = 1e9;
        int i = 0;
        int j = 0;
        unordered_map<char,int> mp;
        
        for(int k=0; k<t.size(); k++){
            mp[t[k]]++;
        }
        
        int needed = mp.size();
        int start = 0;
        
        while(j<n){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                needed--;
            }
            
            if(needed == 0){
                while(needed == 0){
                    if(ans > (j-i+1)){
                        ans = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] > 0){
                        needed++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans != 1e9){
            return s.substr(start, ans);
        }
        return "";
    }
};