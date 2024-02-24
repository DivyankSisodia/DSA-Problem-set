class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         int j=0;
//         int n = nums.size();
        
//         for(i=0;i<n; i++){
//             if(nums[i]!=nums[j]){
//                 j++;
//                 nums[j]=nums[i];
//             }
//         }
//         return j+1;
        
        int i = 1;
        int curr = nums[0];
        
        if(nums.size() < 1){
            return nums.size();
        }
        
        while(i<nums.size()){
            if((nums[i] ^ curr) == 0){
                nums.erase(nums.begin()+i);
                continue;
            }
            
            curr = nums[i];
            i++;
        }
        
        return nums.size();
        
    }
};