class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j=n-1;
        int area = 0;
        
        while(i<j){
            int height = min(arr[i], arr[j]);
            int dist = j-i;
            int maxArea = dist * height;
            area = max(area, maxArea);
            
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
        return area;
    }
};