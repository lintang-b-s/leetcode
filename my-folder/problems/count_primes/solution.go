/*"""
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

prima = bisa dibagi sama 1 sama bilangan itu sendiri
prima= angka % bilangan prima != 0
angka perkalian dari prima itu bukan prima, misal  3*3 = 9 (bukan prima)


bukan prima itu kalau
3*3 , 3*4 , 3*5, 3*6....

0, 1 bukan prima
buat array [True] *n isinya semua  True boolean karena kita akan menandai angka yg bukan prima kurang dari n, menunjukkan angka prima true/bukan
jika ada prime number i , misal i =3, kita tau bahwa kelipatan 3 itu bukan prima
. dan jika i*i melebihi ukuran n, misal 4*4. = 16, n =10 maka gak ada gunanya mencari kelipatan prima yg i*i > n  . maka kita set i = 2 sampai akar(10) karena primanya pasti berada di  bawah 3*3
dari i= 2 sampai akar(10) ,  cari kelipatan  i dan buat di map/arraynya bernilai false


iterasi i = 2 < akar(10) atau 3
0,1,2,3,4,5,6,7,8,9
f f t t t t t t t t
0,1,2,3,4,5,6,7,8,9
f f t t f t f t f t 
0,1,2,3,4,5,6,7,8,9
f f t t f t f t f f
yang prima yg t = 2,3,5,7



"""
*/
import (
	"fmt"
	"math"
)

func countPrimes(n int) int {
	if n < 2 {
		return 0
	}
	primeArray := make([]bool, n)
	for i, _ := range primeArray {
		primeArray[i] = true
	}
	count := 0
	primeArray[1] = false
	primeArray[0] = false
	batas := int(math.Ceil(math.Sqrt(float64(n))))
	for i := 2; i < batas; i++ {
		for j := i * i; j < n; j += i {
			primeArray[j] = false
		}
	}
	count = 0
	for i, _ := range primeArray {
		if primeArray[i] == true {
			count += 1
		}
	}
	return count
}