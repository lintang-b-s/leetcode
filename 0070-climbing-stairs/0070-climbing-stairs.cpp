/*
base case:
n= 0 -> 1
n= 1 -> 1
n=2 -> 2

fn = fn(n-1) + fn(n-2 ) 

testcase:
1. input= 10


*/


class Solution {
    int dp[1000];
public:
    int climbStairs(int n) {
        if (n <=2) {
            return n;
        }
        dp[0] =1;dp[1]=1;dp[2]=2;

        for (int i =3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};