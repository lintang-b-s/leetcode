/*
intuisi:
kecepatan maksimal pastilah jumlah maksimum banana di piles. untuk mencari kecepatan minimum kita harus pakai linear search dari kecepatan maksimal ke angka 1 dan setiap iterasi searchnya kita cek apakah dengan kecepatan itu bisa menghabiskan semua banana. biar lebih cepat bisa pakai binary search

3,6,7,11 h =8


1)array binary
1,    ,6      11
l       m        r
(3/6 +1) + 6/6  + 7/6 + 11/6 = 4 <=8 ? true
karena kecepatan kurang dari h , maka nilai kecepatan minimum ada di mid atau sebelah kiri mid, maka geser right ke mid


2)
1    ,3     6
l     m      r
time = 3/3+ 6/3 + 7/3 + 11/3 = 10<= 8? false
karena jumlah waktu yang dibutuhkan kecepatan 9 lebih dari h(8) maka kecepatan minimum da disebelah kanan atau kecepatanan minimum nya terlalu kecil untuk bisa menghabiskan semua bannana,  left pointer digeser ke kanannya mid

3)
 4,  5   6,
 l   m   r
time = 3/5 + 6/5 + 7/5 + 11/ 5 = 1 + 2 + 2 + 3 = 8 <= 8
karena jumlah waktu yang dibutuhkan untuk menghabiskan banana dg kecepatan 5 sama dg 8, maka kecepatan minimum ada disebelah kiri mid, maka right digeser ke mid
4)
4, 5
lm. r

ide:
kecepatan maksimal pastilah jumlah maksimum banana di piles. untuk mencari 

*/
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = Arrays.stream(piles).max().getAsInt();

        while (left< right){
            int mid = left + (right-left)/2;
            if (canEatAllBananas(piles, mid, h) == true){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return right;
    }

    public boolean canEatAllBananas(int[] piles, int speed, int h){
        int time =0 ;
        for (int bananas : piles){
            if (bananas % speed != 0 ){
                time += (bananas/speed + 1);

            }else{
                time += bananas/speed;
            }
        }
        return time <= h;
    }

}