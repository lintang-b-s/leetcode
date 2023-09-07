
/*

Walktrough:

1,2,1,3,5,6,4
l     m     r

1,2,1,3,5,6,4
        l m r
1,2,1,3,5,6,4
        l r
        m
1,2,1,3,5,6  ,4
          lr
          return 6
*/


class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int left = 0, right =n-1;

        while(left <right){
            int mid=  left + (right- left)/2;
            if (nums[mid] > nums[mid+1]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
}