/*

 1 2 3
 4 5 6
 7 8 9

 transpose
 1 4 7
 2 5 8
 3 6 9

 1 3 4 6 7
 7 6 4 3 1

swapnya matrix{i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
i j = 0, n=3 -> matrix[0][0] =  matrix[0][2]

 swap
 7 4 1
 8 5 2
 9 6 3



 */

class Solution {
     public void rotate(int[][] matrix) {

        int n = matrix.length;
        for (int i =0; i <n ; i++) {
            for (int j=i; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] =  temp;
            }
        }
       
    }
}