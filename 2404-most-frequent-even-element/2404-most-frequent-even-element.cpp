class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int max = 0;
        int ele = -1;
        map<int,int> mp;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }
        
        for(auto it: mp){
            if(it.second > max){
                max = it.second;
                ele = it.first;
            }
            else if(it.second == max && it.first < ele){
                ele = it.first;
            }
        }
        return ele;
    }
};