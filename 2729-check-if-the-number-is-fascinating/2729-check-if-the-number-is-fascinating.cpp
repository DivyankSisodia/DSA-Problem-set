class Solution {
public:
    bool isFascinating(int n) {
        string x = to_string(n);
        string y = to_string(2*n);
        string z = to_string(3*n);
        
        string ans = x+y+z;
        sort(ans.begin(), ans.end());
        if(ans == "123456789"){
            return true;
        }
        return false;
    }
};