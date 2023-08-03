/*
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).




[1,1,1,2,2,3]
   p c.         arr[p] == arr[c] && arr[curr] = arr[prev-1], 1 ==1 , 1 == 1
[1,1,1,2,2,3] 
   p   c,       1 != 2, arr[p] != arr[c] -> p++; arr[p] =arr[c]
[1,1,2,2,2,3]
     p   c.      arr[p] == arr[c] && arr[curr] != arr[prev-1] , p++, 
[1,1,2,2,2,3]   
       p c.   arr[p] == arr[c] && arr[curr] = arr[prev-1] 
[1,1,2,2,2,3]  
       p.  c arr[p] != arr[c]
[1,1,2,2,3,3]  
          

*/
public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length <= 2)
            return A.length;
        int prev = 1; // point to previous
        int curr = 2; // point to current
        while (curr < A.length) {
             if (A[curr] == A[prev] && A[curr] == A[prev - 1]) {
                 curr++;
             } 
             else {
                 prev++;
                 A[prev] = A[curr];
                 curr++;
            }
       }

       return prev + 1;
    }
}