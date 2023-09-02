class Solution {
public int maxSubArray(int[] nums) {
			int res = Integer.MIN_VALUE, curSum = 0;
			for (int num : nums) {
		        if (curSum < 0){
                    curSum =0;
                }
				curSum = curSum +num;
				res = Math.max(res, curSum);
			}
			return res;
		}
}