/*
Input: s = "babad"
Output: "bab"

palindrome:
1. substring length 1
2. substring length 2
3. substring tanpa karakter pertama dan terakhir palindrome & karakter pertama dan terakhir sama
misal "baab" palindrome karena "aa" palindrome && "b"== "b"



*/


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int startIdx= 0;
        int maxLen = 1;
        
        for (int i=0; i<n; i++) {
            dp[i][i] =true;
            if (s[i] == s[i+1] && i < n-1){
                dp[i][i+1] = true;
                startIdx=i;
                maxLen =2;
                
            }
        }
        
        for (int len=3 ; len <= n; ++len){
            for (int l=0; l < n - len +1; ++l){
                int r = l + len - 1;
                
                if (s[l] == s[r] && dp[l+1][r-1] == true) {
                    dp[l][r] = true;
                    if (len > maxLen){
                        maxLen= len;
                        startIdx= l;
                    }
                }
            }
        }
        
       
        
        return s.substr(startIdx, maxLen);
        
    }
};