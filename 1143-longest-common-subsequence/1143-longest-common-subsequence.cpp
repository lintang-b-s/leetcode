class Solution {
        int c[1000+1][1000+1] ;
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(c, -1, sizeof(c));
        int m = text1.size();
        int  n = text2.size();
        return lcs(text1, text2, m, n);
    }

    int lcs(string& text1, string& text2, int n,  int m){
        
    
        
        for (int i = 0; i < n+1 ; i++) {
            for (int j = 0; j < m+1 ; j++) {
               if (i == 0 || j == 0) {
                   c[i][j] = 0;
               } 
            }
        }
        for (int i = 1; i < n+1 ; i++){
            for (int j = 1; j < m+1 ; j++){
                if (text1[i-1] == text2[j-1] ){
                    c[i][j] = c[i-1][j-1] +1;
                }else {
                    c[i][j] = max(0+c[i][j-1], 0+ c[i-1][j]);
                }
            }
        }



        return c[n][m];
        

    }
};