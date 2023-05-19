class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> mp; 

        for(int x:nums)
        {
            if(mp[k-x] > 0)
            {
                mp[k-x]--;
                count++;
            }
            else mp[x]++ ;
        }

        return count ;
    }
};
