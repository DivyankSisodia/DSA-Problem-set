class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
                // k--;
            }
        }
        
        while(k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};