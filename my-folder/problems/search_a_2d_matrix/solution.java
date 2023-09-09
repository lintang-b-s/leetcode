/*
[[1,3,5,7]
, [10,11,16,20]
,[23,30,34,60]]

konversi ke :
[1,3,5,7,10,11,16,20,23,30,34,60]
 l           m                  r
cara konversi -> left=0, right=row*column-1, mid=(left+right)/2, tColumn=mid%col, tRow=mid/col.
misal mid = 5 (11) maka tRow = 5/4 = 1, tCol = 5%4 = 1 sama dg posisi 11 di matrix 2d
lakukann binary search ke array diatas bandingan matrix[trow][tcolumn] dg target


*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int col = matrix[0].length, row=matrix.length;
        int left= 0, right = row*col-1;
        while (left<right){
            int mid = left + (right-left) /2;
            int tCol= mid%col;
            int tRow= mid/col;
            int val = matrix[tRow][tCol];
            if (val >= target){
                right= mid;
            }else{
                left= mid+1;
            }
        }
        int searchedIndex= matrix[left/col][left%col];
        return searchedIndex == target;
    }
}