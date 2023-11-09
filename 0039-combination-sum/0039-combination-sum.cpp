/*
Input: candidates = [2,3,6,7], target = 7
            2,3,6,7
       
                    /.                                     \.       \       \
                   2.                       (               3.         6.   (7)
            /.          \.       \                           /   \.    / \
           2                3.     6,7 (not solution).      3.    5.   6  7
     /  /  /. \.         /.  \                             /\.     
     7  6 2  3 = (7).   3,6,7.     (not solution).        3,5,6,7  
       /. \ \ \.      
    2.    3. 6. 7
=8 >7     9>7 12 13 

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res ;
        vector<int> curNode ;
        backtrack(0, candidates, target, curNode, res);
        return res;
    }

private:
    void backtrack(int s, vector<int>& candidates,  int target, vector<int>& curNode, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0 ){
            res.push_back(curNode);
            return;
        }

        for (int i = s; i < candidates.size(); ++i){
            curNode.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], curNode, res);
            curNode.pop_back();
        }
    }
};