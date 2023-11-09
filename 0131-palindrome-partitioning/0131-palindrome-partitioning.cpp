/*
Input: "aab"
i
        /
0      a
      /             \
1    a              aa
    /               /
2  b               b
["a", "a", "b"]  ["aa","b"]

https://takeuforward.org/wp-content/uploads/2021/12/image-9.png
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> palComb;
        backtrack(s, 0, palComb, res);
        return res;
    }
    
private:
    void backtrack(string s, int i, vector<string>& palComb, 
                  vector<vector<string>>& res) {
        int n = s.length();
        if (i == n) {
            res.push_back(palComb);
            return;
        }
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                palComb.push_back(s.substr(i, j-i+1));
                backtrack(s, j+1, palComb, res);
                palComb.pop_back();
            }
        }
    }
    
private:   
    bool isPalindrome(string s, int l, int r) {
        while (l < r ) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};