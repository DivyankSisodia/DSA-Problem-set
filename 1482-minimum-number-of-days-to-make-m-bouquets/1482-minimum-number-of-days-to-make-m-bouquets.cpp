class Solution {
public:
    
    bool isPossible(vector<int> & arr, int day ,int m ,int k){
        int n = arr.size();
        int cnt = 0;
        int noOfBouquets = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        
        if(noOfBouquets >= m){
            return true;
        }
        return false;
    }
    
    pair<int,int> MaxAndMin(vector<int> &arr){
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        pair<int,int> ans;
        
        for(int i=0 ;i<n; i++){
            if(arr[i] < mini){
                mini = min(arr[i], mini);
            }
        }
        
        for(int i=0 ;i<n; i++){
            if(arr[i] > maxi){
                maxi = max(arr[i], maxi);
            }
        }
        
        ans.first = mini;
        ans.second = maxi;
        
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        pair<int,int> res = MaxAndMin(bloomDay);
        int low = res.first;
        int high = res.second;
        
//         if(bloomDay.size() < (m*k)){
//             return -1;
//         }
        
//         for(int i = low; i<= high; i++){
//             if(isPossible(bloomDay, i, m, k) == true){
//                 return i;
//             }
//         }
//         return -1;
        
        int ans = -1;
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(isPossible(bloomDay, mid, m, k) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};