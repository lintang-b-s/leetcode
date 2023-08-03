/*
count = 1
res =3
3,2,3
    i


*/


class Solution {
    public int majorityElement(int[] nums) {
       int count = 0;
        int res = nums[0];
        for (int i : nums){
             if (count ==0){
                res = i;
            }
            if (res != i) {
                count -=1;
            } else {
                count +=1;
            }
           

        }
        return  res;
    }
}