/*
So, the idea is to initially have pointers on the leftmost and the rightmost indices of the array. We will be using the left pointer to increase the sum and the right pointer to decrease the sum whenever needed. Therefore, the left pointer will move towards the right and the right pointer will move towards the left till one of the following conditions get satisfied:

The sum of the values pointed by the left and the right pointers is equal to target.
The two pointers cross each other. In this case, no valid pair exists in the array.


Pick any two indices in the array and check the sum of their values.
There may arise three possibilities regarding the sum of those two values:

The sum is equal to target: In this case, we are lucky enough and will return the two selected indices.
The sum is less than target: In this case, we would want to increase the sum. Since the array is sorted, we can increase the sum by moving one of the indices towards right,so increasing low by one index.
The sum is greater than target: In this case, we would want to decrease the sum. This can be done by moving one of the indices towards the left,so decreasing high by one index.

from: https://leetcode.com/Nitai_Gauranga/

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() -1;

        while (l<r){
            int sum = numbers[l] + numbers[r];
            if (sum == target){
                return {l+1, r+1};
            }
            
            else if (sum < target){
                // cari elemen yg lebih besar, geser pointer left ke kanan
                l++;
            }
            else{
                // cari element yg lebih kecil , geser pointer right ke kiri
                r--;
            }
        }
        return {};
    }
};