class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return backtrack(n, dp);
    }

    int backtrack(int target, vector<int>& dp) {
        if (target == 0){
            return 0;
        }
        if (dp[target] != -1){
            return dp[target];
        }
        int minCount = INT_MAX;
        for (int n=1; n<=sqrt(target); n++){
            int sqN = n*n;
        
            minCount =   min(  minCount, 1 + backtrack(target -  sqN, dp));
        }

        return dp[target] = minCount;

    }


};