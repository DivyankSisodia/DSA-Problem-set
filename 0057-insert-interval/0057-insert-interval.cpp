class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        a.push_back(b);
        
        sort(a.begin() , a.end());
        
        // merger intervals;
        vector<vector<int>>merge;
        
        for(int i=1; i<a.size(); i++){
             if(a[i][0] <= a[i-1][1]){
                 a[i][1] = max(a[i][1],a[i-1][1]);
                 a[i][0] = min(a[i][0],a[i-1][0]);
                 a[i-1] = {-1,-1};
             }
         }
         
         for(int i=0; i<a.size(); i++){
             if(a[i][0] != -1){
                 merge.push_back(a[i]);
             }
         }
         return merge;
    }
};