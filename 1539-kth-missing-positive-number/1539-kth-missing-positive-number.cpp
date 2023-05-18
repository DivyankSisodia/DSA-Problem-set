class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> set;
        for(int &i: arr) set.insert(i);
        
        for(int i = 1; i <= 2000; i++){
            if(!set.count(i)) k--;
            if(k == 0) return i;
        }
        return -1;
    }
};