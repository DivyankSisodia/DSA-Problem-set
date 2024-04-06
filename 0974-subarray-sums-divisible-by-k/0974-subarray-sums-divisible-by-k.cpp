class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
            // 0(n^3)
        
//         int n = nums.size();
        
//         int cnt = 0;
//         for(int i=0;i<n;i++){
//             for(int j=i; j<n; j++){
//                 int sum = 0;
//                 for(int k=i; k<=j; k++){
//                     sum += nums[k];
//                 }
//                 if(sum % k == 0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
        
        
//         0(n^2)
        // store the cumulative sum
        
//         int n = nums.size();
//         int cnt=0;
        
//         for(int i=1; i<n; i++){
//             nums[i] += nums[i-1];
//         }
        
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 int sum = (i==0) ? nums[j] : nums[j]-nums[i-1];
//                 if(sum %k == 0){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
        
//         0(n)
        // map
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        
//      0 is divisible by 7
        mp[0] = 1;
        
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            
            int rem = sum%k;
            
//          to ignore negative cases we did + - with k with negative integer.
            if(rem<0){
                rem+=k;
            }
            
            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }
            
            mp[rem]++;
        }
        return cnt;
    }
};