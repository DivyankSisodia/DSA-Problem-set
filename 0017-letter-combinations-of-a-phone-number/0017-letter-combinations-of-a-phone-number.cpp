class Solution {
public:
    
    void solve(string digits, vector<string> &ans, string output, int index, string mapping[]){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index]- '0';
        string value = mapping[number];
        
        for(int i=0; i<value.size(); i++){
            solve(digits, ans, output+value[i], index+1, mapping);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output= "";
        
        if(digits.size() == 0){
            return ans;
        }
        int x = 0;
        string mapping[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits,ans,output,x,mapping);
        return ans;
    }
};