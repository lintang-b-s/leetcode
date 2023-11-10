/*
Input: n = 4, k = 2
idx   i
                        /.                   \.           \
 1    1               [1].                   [2].         [3]
                    /.   \        \.         /.  \.        /
 2   2,3,4         [1,2].  [1,3] [1,4].     [2,3].[2,4].  [3,4]
                 /.        /       /.        /.     /.      /
 3            [1,2]     [1,3]     [1,4].   [2,3]. [2,4].  [3,4]
*/ 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1, k, n, curr,res);
        return res;
    }

    void backtrack(int idx, int k, int n, vector<int>& currComb,
     vector<vector<int>>& res) {
        if (currComb.size() == k) {
            res.push_back(currComb);
            return;
        }

        for (int i=idx; i < n+1; i++) {
            currComb.push_back(i);
            backtrack(i+1, k, n, currComb, res);
            currComb.pop_back();
        }
    } 
};