class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
       
        return solve(n-1,m-1,obstacleGrid, dp);
    }

    int solve(int i, int j, vector<vector<int>>& g,
             vector<vector<int>>& dp){

        if (i<0 || j < 0  || g[i][j] == 1) {
            return 0;
        }
        if (i==0 && j==0){
            return 1;
        }

       
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        return dp[i][j] =  solve(i-1, j, g, dp) + solve(i, j-1, g, dp);
    }
};