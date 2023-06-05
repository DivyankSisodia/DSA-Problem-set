class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++){
            product = product * nums[i];
            
            maxi = max(product, maxi);
            if(product == 0){
                product = 1;
            }
        }
        
        product = 1;
        
        for(int i=nums.size()-1; i>=0 ;i--){
            product = product * nums[i];
            maxi = max(maxi, product);
            if(product == 0){
                product = 1;
            }
        }
        return maxi;
    }
};