class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int leftSum=0, rightSum=0, ans=0, n=cardPoints.size();
        
        for(int i=0; i<k; i++){
            leftSum+=cardPoints[i];
        }
        
        ans=max(ans,leftSum);
        int r = n-1;
        for(int i=k-1; i>=0; i--){
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[r--];
            ans=max(ans,leftSum+rightSum);
        }
        return ans;
    }
};