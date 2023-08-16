class Solution {
public:
    struct comp{
    bool operator()( string& s1,string& s2){
        if(s1.size()>s2.size()){
            return true;
        }else if(s1.size()==s2.size()){
            for(int i=0;i<s1.size();i++){
                if(s1[i]-'0'>s2[i]-'0'){
                    return true;
                }
                else if(s1[i]-'0'<s2[i]-'0') {
                        return false;
                }
            }
        }
        return false;
    }   
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,comp>maxh;
        for(auto a:nums){
            maxh.push(a);

        if(maxh.size()>k){
            maxh.pop();
          }
        }
        return maxh.top();
    }
};