class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> hashNumber = new HashSet<>();
        for (int i= 0 ; i < nums.length; i++) {
            if (hashNumber.contains(nums[i])){
                return true;
            }
            hashNumber.add(nums[i]);
        }
        return false;
        
    }
}