class Solution:
    """
    buat 2 pointer i dan j.i pointer elemen paling kiri. j pointer ke elemen paling kanan
    iterasi selama i kurang dari j . cari minimum height dari dua elemen pointer  dan cari lebar dari dua pointer , lalu cari luas container dg mengalikannya. geser pointer yang lebih kecil dengan harapan dapat luas container yg lebih besar
    
    """


    def maxArea(self, height: List[int]) -> int:
        i = 0
        j= len(height)-1
        luas_max = 0
        while (i < j ):
            panjang = j-i
            lebar = min(height[i], height[j])
            luas_sekarang= panjang * lebar
            luas_max = max(luas_max, luas_sekarang )
            if height[i] < height[j]:
                i += 1
            else :
                j -= 1
        return luas_max