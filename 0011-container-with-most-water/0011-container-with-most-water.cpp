class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j = n-1;
        int maxi = 0;
        
        while(i<j){
            int distance = j-i;
            int height = min(arr[i], arr[j]);
            int maxArea = distance * height;
            maxi = max(maxi, maxArea);
            
            if(arr[i] < arr[j]){
                i++;
            }
            else if(arr[i] > arr[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return maxi;
    }
};