class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> mp;
        int i=0; 
        int j=0;
        int ans = 1e9;
        
        for(auto it: t){
            mp[it]++;
        }
        
        int start = 0;
        int cnt = mp.size();
        
        while(j<n){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                cnt--;
            }
            
            if(cnt == 0){
                while(cnt == 0){
                    if(ans > j-i+1){
                        ans = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] > 0){
                        cnt++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans != 1e9){
            return s.substr(start,  ans);
        }
        return "";
    }
};