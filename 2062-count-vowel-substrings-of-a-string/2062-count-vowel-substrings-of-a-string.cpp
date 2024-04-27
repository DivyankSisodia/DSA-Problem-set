class Solution {
public:
    
    bool isVowel(char x){
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }
    
    int countVowelSubstrings(string word) {
        set<char> s;
        int n = word.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
//                 if i get a consonantthen break;
                if(isVowel(word[j]) == false){
                    break;
                }
                
                s.insert(word[j]);
                
                if(s.size() == 5){
                    ans++;
                }
            }
            s.clear();
        }
        return ans;
    }
};