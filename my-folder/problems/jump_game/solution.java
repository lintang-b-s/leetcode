
/*


[2,3,1,1,4]
 i
2,3,1,1,4
  i

2,3,1,1,4
    i
2,3,1,1,4
          i -> return true

reachable(r)=0
r = 2+0, step = 1
r= 3+1 = 4, step =2

input 2:

3,2,1,0,4
i
3,2,1,0,4
  i
3,2,1,0,4
    i
3,2,1,0,4
        i  , i>r (4>3) return false

r = 3+0 = 3
r =



*/
class Solution {
    public boolean canJump(int[] nums) {
        int reachableIndex= 0;
        for (int i=0; i<nums.length ; i++){
            if (i > reachableIndex){
                return false;
            }
            reachableIndex = Math.max(reachableIndex, nums[i]+ i);
        }
        return true;

    }
}