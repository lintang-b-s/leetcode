class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        
        for (int i=0; i< n; i++){
            dp[i][i] =true;
            count +=1;
            if ( i< n-1 && s[i] == s[i+1] ){
                dp[i][i+1]= true;
                count +=1;
            }
        }
        
        for (int len = 3; len <= n ; ++len){
            for (int l=0; l < n-len+1; ++l){
                int r = l + len - 1;
                
                if (s[l] == s[r] && dp[l+1][r-1] == true){
                    dp[l][r] = true;
                    count +=1;
                }
            }
        }

        
        return count;
    }
};