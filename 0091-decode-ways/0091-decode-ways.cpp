/*

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


*/



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0]=1;
        for (int i=1; i<=n; i++){
            if (s[i-1]!= '0'){
                dp[i]= dp[i-1];
            }
            if (i>=2){
                if ( (s[i-2]== '2' && s[i-1] <= '6') || s[i-2] == '1') {
                    dp[i] += dp[i-2];
                }
            }
        }

        for (int i=0; i <n; i++) {
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};