class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
       
        int n=s1.size(), m=s2.size(), k=s3.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        if (n+m != k){
            return false;
        }

        return helper(s1,s2,s3,0,0,0, dp);
    }

    bool helper(string s1, string s2, string s3,
            int i, int j, int k, vector<vector<int>>& dp){
        int n=s1.size(), m=s2.size(), l=s3.size();

        if (k == l){
            return true;
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool ans =false;
        if (i < n && s1[i] == s3[k]){
            ans = ans || helper(s1, s2, s3, i+1, j, k+1,dp);
        }
        if (j<m && s2[j]==s3[k]){
            ans = ans || helper(s1,s2,s3,i,j+1,k+1,dp);
        }

        return dp[i][j] = ans;

    }
};