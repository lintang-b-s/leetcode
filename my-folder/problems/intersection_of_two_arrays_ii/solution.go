/*"""
nums1 = [4,9,5], nums2 = [9,4,9,8,4]
c = { 4:1, 9: 1, 5:1  }
output=[]
buat pointer j =0
loop j<len(nums2) -1. jika elmeen ke j ada di c, maka tambahkan elemn ke j ke intersection dan counter elemen yg ditunjuk j dikurangi 1 karena intersection elemen yg ditunjuk j udah ada


*/

func intersect(nums1 []int, nums2 []int) []int {

	cNums1 := make(map[int]int)

	for _, n := range nums1 {
		cNums1[n] = 0
	}

	for _, n := range nums1 {
		cNums1[n] += 1
	}

	var res []int
	for _, n := range nums2 {
		if cNums1[n] > 0 {
			res = append(res, n)
			cNums1[n] -= 1
		}
	}

	return res
}