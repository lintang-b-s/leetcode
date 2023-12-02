/*
Input: nums = [10,9,2,5,3,7,101,18]
                    i k

utk menghitung len(k), find i dimana i < k &  dimana arr[i] < arr[k] dan ambil len(i) terbesar  . len(k) = len(i) +1 ,. Jika tidak ada i, set len(k) =1
Input: nums = [10,9,2,5,3,7,101,18]

dp= [1,1,1,1,1,1,1,1] ->

dp=[1,1,1,2,2,3,4,3]


*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int lis = 0;
        vector<int> dp(nums.size(), 1);
        for ( int k =0 ; k < nums.size() ; k++){
            for (int i=0; i < k; i++){
                if (nums[i]  < nums[k] ) {
                    dp[k] = max(dp[k], dp[i] + 1);
                }
            }
            lis = max(dp[k], lis);
        }
        return lis;
    }
};