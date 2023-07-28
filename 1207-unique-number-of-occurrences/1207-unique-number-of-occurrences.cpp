class Solution {
public:
//     abe lolu isme frequency check krni h 
//     ki unique h ya nhi
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        set<int> s;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
            s.insert(it.second);
        }
        
        if(mp.size() == s.size()){
            return true;
        }
        return false;
    }
};