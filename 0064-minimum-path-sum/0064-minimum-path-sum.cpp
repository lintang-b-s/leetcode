class Solution {
public:


// // memoization
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
                return solve(grid, n-1, m-1, dp);
    }

    int solve(vector<vector<int>>& grid, int i, int j, 
            vector<vector<int>>& dp){
        if (i < 0 || j < 0){
            return INT_MAX;
        }
        else if (i ==0 && j == 0){
            return grid[i][j];
        }
        if (dp[i][j] != -1){
            return dp[i][j] ;
        }

        return dp[i][j] = grid[i][j] + min(
            solve(grid, i-1, j, dp),
            solve(grid, i , j-1, dp)
        );
    }
};