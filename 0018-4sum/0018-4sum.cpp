class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int start = j+1;
                int end = n-1;
                
                while(start <end){
                    long long sum = arr[i]+arr[j];
                    sum+=arr[start] + arr[end];
                    if(sum == k){
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                    else if(sum>k){
                        end--;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};