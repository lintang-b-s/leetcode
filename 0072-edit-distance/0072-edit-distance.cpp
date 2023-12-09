class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1,  word1, word2, dp);

    }

    int solve( int i, int j,  string& S1, string& S2,vector<vector<int>>& dp) {
  
    if (i < 0)
    // insert j characters
        return j + 1;
    if (j < 0)
    // insert i characters
        return i + 1;
     if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return  dp[i][j]=  0 + solve( i - 1, j - 1, S1, S2, dp);


    else
        return dp[i][j]=  1 + min({solve( i - 1, j - 1, S1, S2,  dp),
                                  solve( i - 1, j, S1, S2, dp),
                                      solve(i, j - 1,S1, S2,  dp)
          }  );
}
};