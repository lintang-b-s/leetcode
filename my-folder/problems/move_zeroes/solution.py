class Solution:
    """
    buat pointer yg nunjuk di awal array. iterasi setaip elemen array jika 
    elemen tidak sama dengan 0 maka elemen di pointer j diassign ke elemen 
    yg lagi diiterasi, lalu j ditambah 1
    setelah iterasi selesai. iterasi array dari j sampai n assign etiap elmeennya ke 0
    """
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0
        n = len(nums)
        for num in nums:
            if (num != 0):
                nums[j] = num
                j +=1
        for x in range (j, n):
            nums[x] = 0