/*

fn = min( dp(n-dj) ) +1 , n>0
f(0)= 0
Input: coins = [1,2,5], amount = 11

*/
class Solution {

public:
    int dp[10001];
    int coinChange(vector<int>& coins, int amount) {


        dp[0]= 0;
        int Max = amount +1 ;

        for (int i=1 ;i <= amount ; i++) {
            int minChange= Max ;
            for (int j=0; j < coins.size() ; j++) {
                if (coins[j] <= i) {
                    
                    minChange = min(minChange, dp[i - coins[j]] + 1);

                }
            }

            dp[i] = minChange;
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};