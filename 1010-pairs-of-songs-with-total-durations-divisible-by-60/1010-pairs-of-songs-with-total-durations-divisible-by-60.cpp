class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt = 0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            int res = time[i] % 60;
            
            int ans = (60-res) % 60;
            
            if(mp.find(ans) != mp.end()){
                cnt += mp[ans];
            }
            mp[res]++;
        }
        return cnt;
    }
};