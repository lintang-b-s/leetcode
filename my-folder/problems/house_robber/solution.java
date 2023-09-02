
    /*
    [1,2,3,1]

    brute force:
         /\
        1  2
       /\   \
      3 1    1

i 0 1 2  3 4 5
v 1 5 3 0  9 4

misal mau rob i=2 atau 3
maka harus bandingin max( max (3+1, 3), 5) = 5
msial mau rob i=3 atau 0
maka harus bandingin max ( max( 0, 0+5), 5) = 5
misal mau rob i =4 atau 9
maka harus bandingin max( max(9+3+1, 9), 5) = 13
misal mau rob i= 5 atau 4
maka harus bandingin max ( max(4+0+5, 4) , 13) = 13



=recurence relation
base case:
dp[0] = houses[0]
dp[1] = max(houses[0], houses[1]

recursive function()
case 1 : steal current house ->
ith_house_stolen = currentHouseMoney + rob(i-2)
case 2: dont steal current house ->
ith_house_not_stolen = rob(i-1)

                rob(5)
        /                               \
    max(current+ rob(3)                 rob(4)
    /               \                      /        \
max(current+ rob(1)   ,  rob(2))      curr + rob(2) rob(3)

*/

class Solution {
      public int rob(int[] nums) {
        int n = nums.length;
        if (n==1){
            return nums[0];
        }

        int[] dp  = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[1], nums[0]);

        for (int i  = 2; i< n ; i++){
            dp[i] = Math.max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];

    }
}