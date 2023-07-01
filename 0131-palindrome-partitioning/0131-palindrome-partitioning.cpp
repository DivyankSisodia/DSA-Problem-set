class Solution {
public:
    
    bool palindrome(string s, int start, int end){
         while (start <= end) {
              if (s[start++] != s[end--])
                return false;
            }
            return true;
    }
    
    void solve(int index, vector<vector<string>> &ans, vector<string>&paths , string s){
        if( index == s.size()){
            ans.push_back(paths);
            return;
        }
        
        for(int i = index; i<s.size(); i++){
            if(palindrome(s, index, i)){
                paths.push_back(s.substr(index, i-index+1));
                solve(i+1, ans, paths, s);
                paths.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> paths;
        solve(0, ans ,paths, s);
        return ans;
    }
//     vector < vector < string >> partition(string s) {
//       vector < vector < string > > res;
//       vector < string > path;
//       partitionHelper(0, s, path, res);
//       return res;
//     }

//   void partitionHelper(int index, string s, vector < string > & path,
//     vector < vector < string > > & res) {
//     if (index == s.size()) {
//       res.push_back(path);
//       return;
//     }
//     for (int i = index; i < s.size(); ++i) {
//       if (isPalindrome(s, index, i)) {
//         path.push_back(s.substr(index, i - index + 1));
//         partitionHelper(i + 1, s, path, res);
//         path.pop_back();
//       }
//     }
//   }

//   bool isPalindrome(string s, int start, int end) {
//     while (start <= end) {
//       if (s[start++] != s[end--])
//         return false;
//     }
//     return true;
//   }
};