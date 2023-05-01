class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<pair<int,int>> s;
        
        // Nearest Smaller from Right (we are taking index of that particular smaller value inside our right array)
        vector<int> right;
        int pseudoRightIndex=n;
        for(int i=n-1;i>=0;i--) {
            if(s.size()==0) {
                right.push_back(pseudoRightIndex);
            }
            else if(s.size()>0 && s.top().first<heights[i]) {
                right.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i]) {
                while(s.size()>0 && s.top().first>=heights[i]) {
                    s.pop();
                }
                if(s.size()==0) {
                    right.push_back(pseudoRightIndex);
                }
                else {
                    right.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
        
        //We will empty the stack for further use
        while(s.size()!=0) {
            s.pop();
        }
        
        
        // Nearest Smaller from Left (we are taking index of that particular smaller value inside our left array)
        vector<int> left;
        int pseudoLeftIndex=-1;
        for(int i=0;i<n;i++) {
            if(s.size()==0) {
                left.push_back(pseudoLeftIndex);
            }
            else if(s.size()>0 && s.top().first<heights[i]) {
                left.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i]) {
                while(s.size()>0 && s.top().first>=heights[i]) {
                    s.pop();
                }
                if(s.size()==0) {
                    left.push_back(pseudoLeftIndex);
                }
                else {
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        
        //Width 
        vector<int> width(n);
        for(int i=0;i<n;i++) {
            width[i] = right[i] - left[i] - 1;
        }
        
        //Area
        vector<int> area(n);
        for(int i=0;i<n;i++) {
            area[i] = heights[i] * width[i];
        }
        
        //Maximum Area
        int result = INT_MIN;
        for(int i=0;i<area.size();i++) {
            if(result < area[i])
                result = area[i];
        }
        return result;
        
    }
};