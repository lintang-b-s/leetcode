
import "math"

 /*
    buat 2 pointer i dan j.i pointer elemen paling kiri. j pointer ke elemen paling kanan
    iterasi selama i kurang dari j . cari minimum height dari dua elemen pointer  dan cari lebar dari dua pointer , lalu cari luas container sekarang dg mengalikannya cari luas max container dg mencari max dari luas_max dan luas_sekarang. geser pointer yang lebih kecil dengan harapan dapat luas container yg lebih besar
    
*/

func maxArea(height []int) int {
	i, j, luas_max := 0, len(height)-1, 0
	for i < j {
		panjang := j - i
		lebar := math.Min(float64(height[i]), float64(height[j]))
		luas_sekarang := lebar * float64(panjang)
		luas_max = int(math.Max(float64(luas_sekarang), float64(luas_max)))
		if height[i] < height[j] {
			i++
		} else {
			j--
		}

	}
	return luas_max

}