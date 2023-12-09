class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices.size(), 1, prices, dp );
    }


    int solve(int idx, int n, int isBuy, vector<int> prices, vector<vector<int>>& dp) {
        if (idx >= n) return 0;

        int profit;

        if (dp[idx][isBuy] != -1) {
            return dp[idx][isBuy];
        }

        if (isBuy ==1 ) { // bisa buy
            profit = max(
              0 +   solve(idx+1, n, 1, prices, dp),  //tidak transaksi
               -prices[idx] +  solve(idx+1, n, 0, prices, dp) // transaksi buy
            );
        }else if (isBuy ==0){ // bisa sell
            profit = max(
                0 + solve(idx+1, n, 0, prices, dp), // tidak transaksi
                prices[idx] + solve(idx+2, n, 1, prices, dp) // transaksi sell & cooldown
            );

        }

        return dp[idx][isBuy]= profit;
    }
};