class Solution {
public:
    int compress(vector<char>& nums) {
        int n = nums.size();
        int cnt = 1;
        string ans;
        
        for(int i=0; i<n; i++){
            while(i<n-1 && nums[i+1] == nums[i]){
                cnt++;
                i++;
            }
            
            ans = ans + nums[i];
            
            if(cnt == 1){
                continue;
            }
            else{
                ans = ans + to_string(cnt);
            }
            cnt = 1;
        }
        
        nums.clear();
        
        for(int i=0; i<ans.size(); i++){
            nums.push_back(ans[i]);
        }
        return nums.size();
    }
};