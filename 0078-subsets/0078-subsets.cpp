/*
back tracking



        input = [1,2,3]
              [   ]
            /               \
          [1]                []
          /   \.             /.  \
      [1,2]   [1]           [2].  []
       / \.    /   \.       /.\.   / \
[1,2,3] [1,2] [1,3] [1]  [2,3] [2] [3] []



*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        generateSubset(nums, 0, res, subset);
        return res;
    }

private:
    void generateSubset(vector<int>&  nums, int i, vector<vector<int>>& res, vector<int>& subset){
        res.push_back(subset);
        for (int j=i; j < nums.size(); j++){
            subset.push_back(nums[j]);
            generateSubset(nums, j+1, res, subset);
            subset.pop_back();
        }
    }
};