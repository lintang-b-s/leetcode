class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        // vector<vector<int> > dp(nums.size() + 1, vector<int>(sum+1, -1));
         unordered_map<string, int> dp;
        return solve(target, nums, 0, dp);
    }

    int solve(int target, vector<int>& nums , int idx,  unordered_map<string, int> &dp) {
        if (idx == nums.size()){
            if (target == 0){
                return 1;
            }
            return 0;
        }
        string key = to_string(idx) + " " + to_string(target);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        target = solve(target - nums[idx], nums, idx+1, dp)
              + solve(target + nums[idx], nums,  idx+1, dp);

        return  dp[key]= target;
    }
};