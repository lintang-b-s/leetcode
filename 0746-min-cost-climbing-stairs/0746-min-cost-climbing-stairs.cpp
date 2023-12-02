/*

dpi = min(dp[i-1] + dp[i-2]) + cost[i]
basecase:
dp[0] = cost[0], dp[1] = cost[1]


testcase:
input :[1,100,1,1,1,100,1,1,100,1]


table: 1 100 2 3 3 103 4 5 104 6 


*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[1001];
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i =2 ; i < cost.size(); i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        for (int i = 0; i< n; i++) {
            cout << dp[i] << " " ;
        }
        return min(dp[n-1], dp[n-2]);
    }
};