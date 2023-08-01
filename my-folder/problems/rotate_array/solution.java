class Solution {
    public void rotate(int[] nums, int k) {
        
        int n = nums.length;
        int kR = k%n;
        
        int[] reversed = rotateSubArray(nums, 0, n);
        rotateSubArray(reversed, 0, kR);
        rotateSubArray(reversed, kR, n);
        
        
    }
    
    public static int[] rotateSubArray(int[] nums, int s, int e) {
        int l=s, r= e-1;
        while (l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
             
            l++;r--;
        }
        return nums;
    }
}