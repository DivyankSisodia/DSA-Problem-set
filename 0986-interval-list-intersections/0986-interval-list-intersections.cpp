class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
        int i = 0;
        int j = 0;
        
        vector<vector<int>>ans;
        int n = arr1.size();
        int m = arr2.size();
        
        while(i<n && j<m){
            int start = max(arr1[i][0] , arr2[j][0]);
            int end = min(arr1[i][1] , arr2[j][1]);
            
            if(start <= end){
                ans.push_back({start,end});
            }
            
            if(arr1[i][1] <= arr2[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};