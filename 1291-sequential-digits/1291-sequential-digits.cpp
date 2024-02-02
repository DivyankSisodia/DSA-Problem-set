class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        
        int ans = 0;
        
        for(int i=1; i<10; i++){
            ans = i;
            for(int j=i+1; j<10; j++){
                ans = ans*10 + j;
                
                if(ans >= low && ans <= high){
                    res.push_back(ans);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};