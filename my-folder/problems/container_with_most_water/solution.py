class Solution:
    """
    buat 2 pointer i dan j.i pointer elemen paling kiri. j pointer ke elemen paling kanan
    iterasi selama i kurang dari j . cari minimum height dari dua elemen pointer  dan cari lebar dari dua pointer , lalu cari luas container sekarang dg mengalikannya cari luas max container dg mencari max dari luas_max dan luas_sekarang. geser pointer yang lebih kecil dengan harapan dapat luas container yg lebih besar


luas. = min(nums[l], nums[r]) * r-l
r= 0, l= len(nums)-1=8
n=9
1,8,6,2,5,4,8,3,7
l               r , luas= 1* 8 = 8
yang bikin luas_max naik itu nilai yg ditunjuk pointer yg lebih kecil nilainya digeser ke nilai yang lebih besar

1,8,6,2,5,4,8,3,7
  l             r , luas = 7 * 7 = 49

iterasi l<r
luas = max(luas, panjang * lebar)
sol:
1,8,6,2,5,4,8,3,7
l               r luas = 8
1,8,6,2,5,4,8,3,7
  l             r luas = 7*7 =49
1,8,6,2,5,4,8,3,7
  l           r.   luas = max(49, 3*6) = 49
1,8,6,2,5,4,8,3,7
  l         r       luas = max(49, 8*5) = 49
1,8,6,2,5,4,8,3,7
    l.      r. luas = max(49, 6*4) = 49

1,8,6,2,5,4,8,3,7
        lr
return luas


    
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