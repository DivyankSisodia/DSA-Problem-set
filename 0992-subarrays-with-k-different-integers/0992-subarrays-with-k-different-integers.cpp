class Solution {
public:
    
//     int helper(vector<int> &nums,int n,int k){
//         int i=0;
//         int j=0;
//         int cnt = 0;
        
//         unordered_map<int,int> mp;
        
//         while(j<n){
//             mp[nums[j]]++;
            
//             while(mp.size() <= k){
//                 mp[nums[i]]--;
//                 if(mp[nums[i]] == 0){
//                     mp.erase(nums[i]);
//                 }
//                 i--;
//             }
//             cnt = cnt + (j-i+1);
//             j++;
//         }
//         return cnt;
//     }
    
    int helper(vector<int> &nums,int n,int k){
        int i=0;
        int j=0;
        int cnt = 0;
        
        unordered_map<int,int> mp;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt = cnt + (j-i+1);
            j++;
        }
        return cnt;
    }
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //         brute force
        
        
//         int n = nums.size();
//         int cnt = 0;
//         // int i=0;
//         // int j=0;
        
//         for(int i=0; i<n; i++){
//             unordered_map<int,int> mp;
//             for(int j=i; j<n; j++){
//                 mp[nums[j]]++;
//                 if(mp.size() == k){
//                     cnt++;
//                 }
//                 else if(mp.size() > k){
//                     break;
//                 }
//             }
//         }
//         return cnt;
        
        
//         optimized
        
//        we need to get subaaray with 2 diff element
//   idea is => get all the element with <=k and <= (k-1)
//   so the left out part will be ==k.
        
        int n = nums.size();
        return helper(nums,n,k) - helper(nums,n,k-1);
        
    }
};