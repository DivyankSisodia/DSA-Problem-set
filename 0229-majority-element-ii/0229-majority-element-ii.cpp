class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1;
        int ele2;
        
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        int ans1 = 0;
        int ans2 = 0;
        vector<int> res;
        
        for(int i=0; i<n; i++){
            if(nums[i] == ele1){
                ans1++;
            }
            if(nums[i] == ele2){
                ans2++;
            }
        }
        // cout<<ans1<<endl;
        
        if(ans1 > n/3){
            res.push_back(ele1);
        }
        if(ans2 > n/3){
            res.push_back(ele2);
        }
        
        return res;
        
    }
};