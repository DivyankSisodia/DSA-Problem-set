class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        // k=k+1;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        int x = ans.size();
        return ans[x-1];
    }
};