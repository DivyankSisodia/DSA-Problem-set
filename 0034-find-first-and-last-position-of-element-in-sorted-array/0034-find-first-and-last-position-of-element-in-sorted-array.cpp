class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        int res = -1;
        s = 0;
        e = n-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(nums[mid] == target){
                res = mid;
                s = mid+1;
            }
            else if(nums[mid] <target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        vector<int> temp;
        temp.push_back(ans);
        temp.push_back(res);
        return temp;
    }
};