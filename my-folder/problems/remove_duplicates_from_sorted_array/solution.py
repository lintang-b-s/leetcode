class Solution:
    """
    buat pointer j buat ngelacak elemen yg unik
    loop arraynya jika elemen ke i tidak sama dg elemen selanjutnya, maka tukar dg  elemen yg ditunjuk pointer j
    setelah loop. elemen pointer ke j di ganti dg elemen terakhir

    """
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for j in range(0, len(nums) -1):
            if nums[j] != nums[ j +1]:
                nums[i] = nums[j]
                i += 1

        nums[i] = nums[ len(nums) -1]
        i += 1
        return i
                
        