/*

thought process: https://1drv.ms/u/s!AjydC1xTTXtndgISZV4RA6jiwj8

time comeplexity; O(9^k)
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, 1, k, n, curr);
        return ans;
    }


    void backtrack(vector<vector<int>>& ans, int currentNum, int k, int n,
       vector<int>& curr ){
        if (curr.size() == k) {
            if (n ==0) {
                ans.push_back(curr);
            }
            return;
        }
        if (n < 0 || curr.size() > k){
            return;
        }

        for (int num = currentNum; num<=9 ; num++){
            curr.push_back(num);
            backtrack(ans, num+1, k, n-num, curr);
            curr.pop_back();
        }
    } 
};