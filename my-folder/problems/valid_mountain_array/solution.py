class Solution:

    """
    buat pointer i =1
    iterasi array selama  i kurang dari panjang array dan jika elemen array ke i lebih dari elemen array sebelumnya (cek untuk array menaik) ,lalu tambah pointer i dg 1. jika dua kondisi tak dipenuhi, keluar dari loop.
    cek jika iterasi pertama tidak selesai dan pointer i menunjuk ke akhir dari array(arraynya menaik sampai akhir), jika ya return false.
    iterasi lagi selama i < len(arr) dan elemen ke i kurang dari elemen sebelumnya (cek array menurun) dan tambah pointer i dg 1.
    cek jika pointer i sampai di akhir array(array menurun dari elemen terakhir array yg menaik  sampai akhir dari array)
    """

    def validMountainArray(self, arr: List[int]) -> bool:
        i= 1    
        while(i < len(arr) and arr[i-1] < arr[i]):
            i += 1
        if (i == 1 or i == len(arr)):
            return False
        while( i < len(arr) and arr[i-1] > arr[i]  ):
            i +=1

        return len(arr) == i
