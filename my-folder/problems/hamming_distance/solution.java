/*

1   (0 0 0 1)
4   (0 1 0 0)

xor jika  x dan y beda = 1

jika x dan y sama  = 0

1   (0 0 0 1)
4   (0 1 0 0)
           xor
     0  1  0 1

res += 1 + 1;

*/
class Solution {
    public int hammingDistance(int x, int y) {
        int result=  0;
        while(x > 0 || y > 0){
            result += (x%2) ^ (y%2);
            x >>= 1;
            y >>=1;
        }
        return result;
    }
}