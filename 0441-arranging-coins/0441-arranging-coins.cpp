class Solution {
public:
    int arrangeCoins(int n) {
        // formula used
        // k * (k + 1) <= 2*N;
        
        long left = 0;
        long right = n;
        while(left <= right){
            
            long mid = left + (right - right)/2;
            long curr = mid*(mid+1)/2;
            
            if(curr == n){
                return mid;
            }
            
            if(curr > n){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return (int)right;
        
    }
};