/*
123
123 %10 = 3
123/10 = 12  (perloop)
12 %10  = 2
12 /10 = 1
1 %10 = 1
1/10 = 0


res = 0
res = 0*10 +3
res  = 3*10 + 2
res = 32*10 + 1


res = 0 + 300 + 20 + 1= 321

x%10
res=  214748364_
max%10
INT.MAX  = 2147483647 ->(sebelum angka terakhir ditambahkan) res> 214748364 || res == 214748364  and digit >= 7 -> return 0
INT.MIN = -2147483647 -> (sebelum angka terakhir ditambahkan) res < -2147483647 || res == --2147483647 and digit <= 7 ->return 0
res > int.max /10 or res == int.max/10 and digit >= max%10 ->return 0


res =321



 */
class Solution {
        public int reverse(int x){
        int res= 0 ;
        while (x != 0){
            int digit = x % 10;
             x = x/10;
             if (res > Integer.MAX_VALUE /10 || res == Integer.MAX_VALUE/10 && digit >= Integer.MAX_VALUE%10) {
                 return 0;
             }else if (res < Integer.MIN_VALUE /10 || res == Integer.MIN_VALUE/10 && digit <= Integer.MIN_VALUE%10){
                 return 0;
             }

            res = res*10 + digit;
        }
        return res;
    }



}