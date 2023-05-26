class Solution {
public:
     bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        int temp = 0;
        // unordered_set<char> s{'a','e','i','o','u'};
        
        while(j<n){
            // if my current char is vowel then increament temp
            if(isVowel(s[j])){
                // j++;
                temp++;
            }     
            
            if(j-i == k){
                // agar i pr koi vowel h aur window slide krni h toh i wale vowel ko decrease kia
                if(isVowel(s[i])){
                    temp--;
                }
                i++;
                // j++;
            }
            ans = max(ans, temp);
            j++;
        }
        return ans;
    }
};

