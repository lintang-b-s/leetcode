/*
intuisi:
int reachableIndex= 0
-  iterate setiap num. , set reachableindex dg jump ke index terjauh.
- jka i > reachableIndex berarti stuck di reachableIndex & gak bisa ke index terakhir

Input: nums = [2,3,1,1,4]
reachableIndex=0
1. i=0  -> i < reachableIndex-> reachableIndex=2 + 0 =2
2. i=1 -> i < reachableIndex -> reachableIndex = max(2, 3+1) = 4
3. i =2 -> i < reachableIndex -> reachableIndex= max(4, 1+2) =4
.....
return true
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachableIndex = 0;
        for (int i=0; i <nums.size() ; i++){
            if ( i > reachableIndex ) {
                return false;
            }
            reachableIndex = max(reachableIndex, nums[i] + i);
        }
        return true;
    }
};