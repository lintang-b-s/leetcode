/*
sama kaya combinationn sum bedanya ada counter table untuk mengetahui berapa kali candidate dipakai.


Kasus 2

Input: candidates = [2,5,2,1,2], target = 5
counter = [ [2,3], [5,1], [1,1]  ]
                        
                           /.   \.     \
      [2,2]              2.     (5).   1
                      / \  \.           
     [2,1]          2.  5.  1 
                   /\\      
 c=   [[2,0]]     2 5,(1). 





intuisi:
Here are a few steps on how we can implement the above intuition:

First of all, we build a counter table out of the given list of numbers.

We would then use this counter table during our backtracking process, which we define as the function backtrack(comb, remain, curr, candidate_groups, results).
In order to keep the state of each backtracking step, we use quite a few parameters in the function, which we elaborate as follows:

comb: the combination we built so far at each step.
remain: the remaining sum that we need to fill, in order to reach the target sum.
curr: the cursor that points to the current group of number that we are using from the counter table.
counter: the current counter table.
results: the final combinations that have the target sum.
At each invocation of the backtracking function, we first check if we reach the target sum (i.e. sum(comb) = target), and if we should stop the exploration simply because the sum of current combination goes beyond the desired target.

If there is still some remaining sum to fill, we will then iterate through the current counter table to pick the next candidate.

Once we pick a candidate, we then continue the exploration by invocating the backtrack() function with the updated states.
More importantly, at the end of each exploration, we need to revert the state we updated before, in order to start off a clean slate for the next exploration.
It is due to this backtracking operation, the algorithm got its name.


*/


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        unordered_map<int, int> counterHash;

        for (auto & candidate: candidates) {
            if (counterHash.find(candidate) != counterHash.end())   { 
             counterHash[candidate] = counterHash[candidate]  +1;
            } else {
                counterHash[candidate] = 1;
            }
        }

        vector<vector<int>> counterList;
        for(const auto & pair: counterHash) {
            vector<int> hash;
            hash.push_back(pair.first);
            hash.push_back( pair.second);
            counterList.push_back(hash);
        }

        backtrack(comb, target, 0, counterList, res);
        return res;
    }

private:
    void backtrack(vector<int>& comb, int remain, int curr, 
    vector<vector<int>>& counter, vector<vector<int>>& res) {
        if (remain < 0) {
            return;
        }
        if (remain == 0) {
            res.push_back(comb);
            return;
        }

        for (int nextCurr = curr; nextCurr < counter.size(); ++nextCurr) {
            vector<int> entry = counter[nextCurr];
            int candidate = entry[0], freq = entry[1];

            if (freq <=0) {
                
                continue;
            }

            comb.push_back(candidate);
            vector<int> cd;
            cd.push_back(candidate);
            cd.push_back( freq - 1);
            counter[nextCurr] = cd;

            backtrack(comb, remain - candidate, nextCurr, counter, res);

            vector<int> cdBack;
            cdBack.push_back(candidate );
            cdBack.push_back(freq);
            counter[nextCurr] = cdBack;

            counter[nextCurr] = cdBack;
            comb.pop_back();
        }
    }
};