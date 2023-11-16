/*

Input: nums = [2,3,1,1,4]
intuisi: 
We initialize end and farthest to 0, and ans to 0, where end is the current possible farthest point we could reach, farthest is the farthest point that we can reach from i, and ans is the minimum number of jumps.

We iterate the array from the beginning to the end.

At each position, we update farthest with the furthest point we can reach from i.
If farthest is greater than or equal to the last index, we increment ans and break (because we can reach the last index from the current index).
If i reaches end, it means we have visited all the items on the current level, so we increment ans and set end to farthest.
Finally, we return ans as the result. This approach ensures we make the minimum number of jumps to reach the last index.


nums = [2,3,1,1,4]
end =0 , ans=0
farthest=0

1.i=0
farthest = max(0,0+2)=2
i== end -> ans+=1 = 1 ,end =farthest = max(0,0+2)=2
2.i=1
farthest = max(2,1+3)=4
farthest == nums.size -> ans+=1=2 return ans
 
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int reachableIndex = 0,n = nums.size() -1, totalJump=0, lastFurthestIndex = 0;
        for (int i =0 ;i < nums.size() -1; i++){
            // iterate sampai index terakhir ke dua, karena di idx terakhir kedua udah bisa sampai last index.
            reachableIndex = max(reachableIndex, nums[i]+i); // index terjauh yg dapat dikunjungi dari i
            if (reachableIndex >= nums.size() -1){
                // reachable index adalaha index terakhir array
                totalJump++;
                return totalJump;
            }
            if (i == lastFurthestIndex){
                // jika saat ini mengunjungi index  terjauh yg dapat dikunjungi 
                totalJump++; // increment ans, karna mau jump lagi
                lastFurthestIndex= reachableIndex; // set furthestindex ke reachableindex dari i 
            }
        }
        return totalJump;
    }
};