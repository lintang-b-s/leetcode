/*
dp[i] = max(dp[i-1], dp[i-2] + nums[i]) , i> 1
i== 1 -> max(dp[i-1, nums[i])

basecase:
dp[0] = nums[0], dp[1] = nums[1];

exclude nums[0] & nums[1]
*/

class Solution {
    int dp[1001];
public:
    int rob(vector<int>& nums) {
        if (nums.size()== 1){
            return nums[0];
        }
        vector<int> withoutFirst(nums.begin()+1, nums.end());
        vector<int>  withoutend(nums.begin(), nums.end()- 1);

       

        return max( robDp(withoutFirst), robDp(withoutend));
    }

    int robDp(vector<int>& nums){
       if (nums.size()== 1){
            return nums[0];
        }
        dp[0]= nums[0];
        dp[1] = nums[1];
        for(int i=1; i < nums.size(); i++){
            if (i>1){
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }else {
                dp[i] = max(dp[i-1], nums[i]);
            }
        }
        return dp[nums.size()-1];
    }
};