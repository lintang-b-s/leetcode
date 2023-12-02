/*
Input: s = "bbbab"



*/

class Solution {
int dp[1001][1001];
public:
    
    int longestPalindromeSubseq(string s) {    
        memset(dp, -1, sizeof(dp)); 
        return lps( 0, s.size()-1, s);
    }

    int lps( int left, int right, string&s ){
        if (dp[left][right] != -1){
             return dp[left][right];
         }

         if (left  > right ) return 0;
         
        if (left == right){
            // 1 karakter palindrrome
            return 1;
        }

        

        if (s[left] == s[right]) {
            return 2 + lps(left+1, right-1, s);
        }
        return dp[left][right] =  max(lps(left+1, right, s), lps(left, right-1, s));
    }

    
};