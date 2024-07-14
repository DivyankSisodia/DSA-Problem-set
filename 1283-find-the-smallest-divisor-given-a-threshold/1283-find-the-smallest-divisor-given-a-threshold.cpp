class Solution {
public:
    
    int maxElement(vector<int> &arr){
        int maxi = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > maxi){
                maxi = max(maxi, arr[i]);
            }
        }
        return maxi;
    }
    
    int calculateSum(vector<int> &arr, int divisor){
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += ceil((double)(arr[i])/ (double)(divisor));
        }
        return sum;
    }
    
    
    
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1;
        int high = maxElement(arr);
        
        while(low<=high){
            int mid = (low + high)/ 2;
            
            if(calculateSum(arr, mid) <= threshold){
                high = mid - 1;
            }
            
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};