class Solution {
public:
    int mod = 1000000007;
    int countPairs(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> power;
        unordered_map<int,int> mp;
        for(int i=0; i<=21; i++){
            power.push_back(pow(2,i));
        }
        
        for(int i= 0; i<n; i++){
            for(int j = 0; j<power.size(); j++){
                if(mp.find(power[j] - arr[i]) != mp.end()){
                    ans = (ans+ mp[power[j] - arr[i]]) % mod;
                }
            }
            mp[arr[i]]++;
        }
        return ans%mod;
    }
};