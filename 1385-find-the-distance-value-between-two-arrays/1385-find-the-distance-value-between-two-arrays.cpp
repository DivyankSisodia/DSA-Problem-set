class Solution {
public:
    
    bool solve(int target, vector<int>&arr, int d){
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(abs(arr[mid] - target) <= d){
                return false;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int cnt = 0;
        
        for(auto it: arr1){
            if(solve(it, arr2, d) == true){
                cnt++;
            }
        }
        return cnt;
    }
};