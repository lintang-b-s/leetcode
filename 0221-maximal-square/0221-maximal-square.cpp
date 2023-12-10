/*
dp[i][j]=1+  min({
            helper(m, i+1, j),
            helper(m, i, j+1),
            helper(m, i+1, j+1)
        });

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                ans = max(ans, helper(matrix, i, j, dp));    
            }
        }
        return ans*ans;
    }

    int helper(vector<vector<char>>& m, int i, int j,
        vector<vector<int>>& dp){
        if (i > m.size()-1 || j > m[0].size()-1){
            return 0;
        }
         if (dp[i][j] != -1){
            return dp[i][j];
        }
        if (m[i][j] =='0'){
            return 0;
        }

       
        
        return dp[i][j] =  1+  min({
            helper(m, i+1, j,dp),
            helper(m, i, j+1,dp),
            helper(m, i+1, j+1,dp)
        });

    }
};