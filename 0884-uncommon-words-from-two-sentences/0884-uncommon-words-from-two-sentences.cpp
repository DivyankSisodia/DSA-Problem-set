class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        string word;
        
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != ' '){
                word.push_back(s1[i]);
            }
            if(s1[i] == ' ' || i == s1.size()-1){
                mp[word]++;
                word = "";
            }
        }
        
        for(int i=0; i<s2.size(); i++){
            if(s2[i] != ' '){
                word.push_back(s2[i]);
            }
            if(s2[i] == ' ' || i == s2.size()-1){
                mp[word]++;
                word = "";
            }
        }
        
        vector<string> ans;
        
        for(auto it: mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};