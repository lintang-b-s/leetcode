/*

dp[i] = max(dp[i-1], dp[i-2] + nums[i]) i>1
        max(dp[i-1], nums[i])  i==1
dp[0] = nums[0]
dp[1] = nums[1]


*/
class Solution {
    int dp[1001];
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i= 1; i < nums.size();i++ ){
            if (i >1 ) {
                 dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }else {
                dp[i] = max(dp[i-1], nums[i]);
            }
           

        }
        return dp[nums.size()-1];
    }
};