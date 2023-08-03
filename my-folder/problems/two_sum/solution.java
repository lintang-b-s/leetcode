/*
hashmap = {2: 0}
[2,7,11,15] target = 9
 i             elemen selain i yg dijumlah = target -> taget- nums[i]
(9-2)

[2,7,11,15]
   i
(9-7) return [map[2], i]

 */


class Solution {
 public static int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> map = new HashMap<>();
        int[] res = new int[2];
        for (int i = 0; i< nums.length; i++){
            int num = nums[i];
            int other = target - num;
            if (map.containsKey(other)){
                res[0] = map.get(other);res[1] = i;
                return res;
            }
            map.put(num, i);
        }


        return res;
    }
}