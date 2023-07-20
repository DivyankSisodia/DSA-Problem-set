class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int negone, int k) {
//         vector<int> ans(one+zero+negone);
//         for(int i=0; i<ans.size(); i++){
//             if(one > 0){
//                 ans[i] = 1;
//                 one--;
//             }
//             else if( zero > 0){
//                 ans[i] = 0;
//                 zero--;
//             }
//             else{
//                 ans[i] = -1;
//                 negone--;
//             }
//         }
        
//         // for(auto it: ans){
//         //     cout<<it<<" "<<endl;
//         // }
//         int sum = 0;
//         for(int i=0; i<k; i++){
//             sum = sum + ans[i];
//         }
//         return sum;
        priority_queue<int> pq;
        while(one--) pq.push(1);
        while(zero--) pq.push(0);
        while(negone--) pq.push(-1);
        
        int ans = 0;
        while(k--) ans += pq.top(), pq.pop();
        return ans;
    }
};