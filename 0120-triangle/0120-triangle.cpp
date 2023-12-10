class Solution {
    
public:
 // bottom up
    int minimumTotal(vector<vector<int>>& triangle) { 
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i=1 ; i< n ; i++){
            for (int j=0; j<triangle[i].size(); j++){
                if (j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if (j==triangle[i].size()-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else {
                    dp[i][j]= min(dp[i-1][j], dp[i-1][j-1]) 
                        + triangle[i][j];
                }
            }
        }
    
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }

// memoization
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n, -1));
    //     return solve(triangle, 0, 0, dp);

    // }

    // int solve(vector<vector<int>>& t, int r, int c, 
    //     vector<vector<int>> dp) {
    //     if (r == t.size()){
    //         return 0;
    //     }
       
    //    if (dp[r][c] !=  -1){
    //        return dp[r][c];
    //    }

    //    return dp[r][c] =  t[r][c] + min(solve(t, r+1, c, dp), 
    //                 solve(t, r+1, c+1, dp));
    // }
};