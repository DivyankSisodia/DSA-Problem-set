class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
//         not space optimised
        
//         list<int> l;
        
        
//         for(int i=0; i<n; i++){
//             if(nums[i] % 2 == 0){
//                 l.push_front(nums[i]);
//             }
//             else{
//                 l.push_back(nums[i]);
//             }
//         }
        
//         for(auto it: l){
//             ans.push_back(it);
//         }
//         return ans;
        
//         optimised
        
        int i= 0;
        int j=n-1;
        
        for(int k = 0; k <n; k++){
            if(nums[k] % 2 == 1){
                ans[j] = nums[k];
                j--;
            }
            else{
                ans[i] = nums[k];
                i++;
            }
        }
        
        return ans;
        
    }
};