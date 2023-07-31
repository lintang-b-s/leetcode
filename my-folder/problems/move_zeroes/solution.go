/*
    buat pointer yg nunjuk di awal array. iterasi setaip elemen array jika 
    elemen tidak sama dengan 0 maka elemen di pointer j diassign ke elemen 
    yg lagi diiterasi, lalu j ditambah 1
    setelah iterasi selesai. iterasi array dari j sampai n assign etiap elmeennya ke 0
 */




func moveZeroes(nums []int) {
	j := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			nums[j] = nums[i]
			j++
		}
	}

	for j < len(nums) {
		nums[j] = 0
		j++
	}

	

}