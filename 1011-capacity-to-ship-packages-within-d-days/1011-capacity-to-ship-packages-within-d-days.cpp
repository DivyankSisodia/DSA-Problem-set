class Solution {
public:
    int calculateDays(vector<int> &arr, int capacity){
        int days = 1, load = 0;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] + load > capacity){
                days += 1;
                load = arr[i];
            }
            else{
                load += arr[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int noOfDays = calculateDays(weights, mid);
            
            if(noOfDays <= days){
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