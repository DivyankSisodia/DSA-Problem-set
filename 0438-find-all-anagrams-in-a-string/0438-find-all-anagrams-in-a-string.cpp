class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n){
            return {};
        }
        vector<int>sm(26,0);
        vector<int>pm(26,0);
        vector<int>ans;
        int i = 0;
        int j = 0;
        while(i<m){
            sm[s[i]-'a']++;
            pm[p[i]-'a']++;
            i++;
        }
        if(sm == pm){
                ans.push_back(j);
            }
        while(i<n){
            sm[s[j++]-'a']--;
            sm[s[i++]-'a']++;
            if(sm == pm){
                ans.push_back(j);
            }
        }
        return ans;
    }
};