class Solution {
public:
    int alternateDigitSum(int n) {
        // int sum1 = 0;
        if(n == 0) return 0;
        vector<int> ans;
        while(n){
            int digit = n%10;
            ans.push_back(digit);
            n = n/10;
        }
        int sum= 0;
        reverse(ans.begin(),ans.end());
        bool flag = true;
        for(auto it: ans){
            if(flag){
                sum = sum + it;
                flag = false;
            }
            else{
                sum = sum - it;
                flag = true;
            }
        }
        return sum;
    }
};