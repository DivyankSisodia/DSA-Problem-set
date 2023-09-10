class Solution {
public:
//     step 1: if n is 3 then we know answer for n = 2
//     step 2: see what could be the possible cases if we place P3 in between P1/D1 and P2/D2
//     it might be coming as x = (2*n-1) then y = x+(x+1)/2;
//     then answer could be find as y * prev ans
    
// What Does 2i - 1 and 2i Signify?

// For each order i, there are i pickups and i deliveries in the sequence, making 2i positions in total.
// If you are placing the pickup for the i-th order, you have 2i - 1 choices. Why? Because the i-th delivery can go in any of the remaining i positions.
// Similarly, for the delivery, you have i options because it can go anywhere after its corresponding pickup.
    
    int mod = 1000000007;
    
    int countOrders(int n) {
        vector<long> dp(501);
        dp[1] = 1;
        dp[2] = 6;
        for(int i=3; i<=n; i++){
            int findingOddNumber = 2*i-1;
            int NumberofCases = ((findingOddNumber * (findingOddNumber + 1))/2) %1000000007;
            dp[i] = (dp[i-1] * (NumberofCases))%1000000007;
        }
        return (int)dp[n]%1000000007;
    }
};