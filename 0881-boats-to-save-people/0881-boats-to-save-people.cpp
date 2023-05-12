class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        sort(v.begin(),v.end());
        int n = v.size();
        int s = 0;
        int e = n-1;
        int ans = 0;
        while(s<=e){
            // heavy wala akela gya
            if(v[e] == limit){
                ans++;
                e--;
            }
            // again heavy goes alone
            else if(v[s] + v[e] > limit){
                ans++;
                e--;
            }
            // both goes in single boat
            // condn v[s] + v[e] == limit
            else{
                ans++;
                s++;
                e--;
            }
        }
        return ans;
    }
};