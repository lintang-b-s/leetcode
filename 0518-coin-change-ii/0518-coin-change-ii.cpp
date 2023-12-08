class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(amount, coins, 0, 0, dp);
    }

    int solve(int amount, vector<int>&coins, int total, int idx, vector<vector<int>>& dp){
        if (amount ==0){
            return 1;
        }

        if (idx==coins.size()){
            return 0;
        }

        if (dp[idx][amount] != -1){
            return dp[idx][amount];
        }


        int take=0;

        int dontTake = solve(amount, coins, total, idx+1, dp);

        if (amount - coins[idx] >= 0){
             take = solve(amount - coins[idx], coins, total, idx, dp);

        }

        total = take + dontTake;
        return dp[idx][amount] = total;
    }
};