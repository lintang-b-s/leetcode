class Solution {
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m= matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans=0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++){
                ans = max(ans, dfs(matrix, i,j, -1, dp));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>&  m, int r, int c, int prevVal,
               vector<vector<int>>& dp) {
        if (r < 0 || c < 0 
            || r == m.size() || c == m[0].size()  || 
            m[r][c] <= prevVal) {
                return 0;
            }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int res = 1;
        res= max(res, 1+dfs(m, r+1, c, m[r][c], dp));
        res= max(res, 1+dfs(m, r-1, c, m[r][c], dp));
        res= max(res, 1+dfs(m, r, c+1, m[r][c], dp));
        res= max(res, 1+dfs(m, r, c-1, m[r][c], dp));
        return dp[r][c] = res;

    }
};