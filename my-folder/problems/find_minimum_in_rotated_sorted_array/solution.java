

/*
    3,4,5,6,7,8,9,1,2
      m         r

     karena m=4 < r=9, kita tahu bahwa minimum ada di m dan sebelah kiri m, maka right=mid

    3,4,5,6,7,8,9,1,2
          m         r

       karena m=6 > r=2 kita tahu bahwa  minimum ada di disebelah kanan mid atau di mid+1 sampai terakhir, maka


*/


class Solution {
     public int findMin(int[] nums) {
        int left = 0, right= nums.length-1;
        
        while(left  < right){
            int mid = left + (right- left)/2;
            if (nums[mid] > nums[right]){
                left = mid+1;
            }else{ // nums[mid] < nums[right]
                right= mid;
            }
        }
        return nums[left];
    }
}