class Solution {
    int dp[101][101];
public:
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }

    int solve(int i ,int j){
        if (i==0 && j == 0) {
            return 1;
        }else if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j]){
            return dp[i][j];
        }

        int up = solve(i-1, j);
        int left = solve(i, j-1);
        return dp[i][j] = up+left;
    }
};