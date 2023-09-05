/*
1,2,3,1, k=3

0>3 ; {1}
1>3 ; {}



*/
class Solution {
   public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> numberSet = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            if(numberSet.containsKey(nums[i]) && i-numberSet.get(nums[i]) <= k){
                return true;
            }
            numberSet.put(nums[i], i);
        }
        return false;

    }
}