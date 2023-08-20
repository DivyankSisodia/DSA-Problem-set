class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int,string>> res;
        int n = names.size(); 
        
        for(int i=0; i<n; i++){
            res.push_back({heights[i], names[i]});
        }
        
        sort(res.begin(), res.end(), greater<>());
        
        for(auto it: res){
            ans.push_back(it.second);
        }
        return ans;
    }
};