/*

[3,1,5,9,12]
        15.      n
        /\.      5
  t   3. 15.     4
      /. /\
t   3.  6 15       3
    /.  
t  3.            2
  / \
 2. 0            1
 f.  t           0



dp[n][sum] = isSubsetSum (arr, n, sum/2) = isSubsetSum (arr, n-1, sum/2) || isSubsetSum (arr, n-1, sum/2 – arr[n-1])        ,   nums[n-1] < sum

*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum=0;
        for (int& n: nums){
            sum += n;
        }
        if (sum %2 != 0) {
            return false;
        }




        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return isEqual(dp, nums, n, sum/2);
    }

    bool isEqual(vector<vector<int>>& dp, vector<int>& nums, int n, int sum
                )
        {
            // base case
            if (sum==0) {
                return true;
            }
            if (n==0 && sum != 0) {
                return false;
            }
            if (dp[n][sum] != -1) {
                return dp[n][sum];
            }
            

            if (nums[n-1 ] > sum){
                return isEqual(dp, nums, n-1, sum);
            }

            return dp[n][sum] = isEqual(dp, nums, n-1, sum) || 
                isEqual(dp, nums, n-1, sum-nums[n-1]);
        }
};