class Solution {
       public int longestConsecutive(int[] nums) {
        int n = nums.length;
        HashSet<Integer> set = new HashSet<>();
        int ans = 0;
        
        for (int i=0; i<n; i++){
            set.add(nums[i]);
        }
        
        for (int i = 0; i<n; i++){
            if (!set.contains(nums[i] - 1)){
                int numConsecutive = nums[i];
                while (set.contains(numConsecutive)){
                    set.remove(Integer.valueOf(numConsecutive));
                    numConsecutive++;
                }
                if (numConsecutive - nums[i] > ans){
                    ans = numConsecutive - nums[i];
                }
            }
        }
        return ans;
    }
}