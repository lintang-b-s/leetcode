class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for (int i=1; i<= s.size(); i++) {
            cout << "i: " << i << endl;
            for (int j=0; j<i; j++){
                if (dp[j] &&  set.count(s.substr(j, i-j))){
                    cout << s.substr(j, i-j) << endl;
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];

    }

};