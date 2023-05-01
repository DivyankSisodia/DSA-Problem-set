class Solution {
public:
     vector<int> nsl(vector<int>  heights)
    {
        vector <int> left;
        stack <pair<int ,int >> s;
        int pseudoind=-1;
        
        for(int i=0;i<heights.size();i++)
        {
            if(s.size()==0)
            {
              left.push_back(pseudoind);
            }
            else if(s.size()>0 and s.top().first<heights[i])
                left.push_back(s.top().second);
            else if(s.size()>0 and s.top().first >= heights[i])
            {
                while(s.size()>0 and s.top().first >= heights[i])
                    s.pop();
                if(s.size()==0)
                    left.push_back(pseudoind);
                else 
                    left.push_back(s.top().second);
                
                    
            }
            s.push({heights[i],i});
            
        }
        return left;
        
        
    }
 //========================================================================
    vector <int> nsr(vector <int> heights)
    {
        
      vector <int> right;
        stack <pair<int ,int >> s;
        int pseudoind=heights.size();
        
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
              right.push_back(pseudoind);
            }
            else if(s.size()>0 and s.top().first<heights[i])
                right.push_back(s.top().second);
            else if(s.size()>0 and s.top().first >= heights[i])
            {
                while(s.size()>0 and s.top().first >= heights[i])
                    s.pop();
                if(s.size()==0)
                    right.push_back(pseudoind);
                else 
                    right.push_back(s.top().second);
                
                    
            }
            s.push({heights[i],i});
            
        }
        return right;
          
        
    }
    
    //========================================================================
    
    
    int mah(vector<int> heights)
    {
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        
        reverse(right.begin(),right.end());
        int n=heights.size();
        
        int mx=INT_MIN;
        
        
        for(int i=0;i<heights.size();i++)
          {
            int w=right[i]-left[i]-1;
            mx=max(mx,w*heights[i]);
            }
        
   
        return mx;
        
        
        
    }
    
    
    
    
    
    //============================================================================
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
         int r=matrix.size();
        int c=matrix[0].size();
        vector<int> v(c,0);
      
        int mx=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+1;
                }
            }
            mx=max(mx,mah(v));
        }
        return mx;
    }
};