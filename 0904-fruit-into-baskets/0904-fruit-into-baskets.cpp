class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int> mp;
        int i=0;
        int j =0;
        int n = arr.size();
        int ans = 0;
        
        while(j<n){
            mp[arr[j]]++;
            // if(mp.size() < 2){
            //     j++;
            // }
            if(mp.size() <= 2){
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                mp[arr[i]]--;
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};