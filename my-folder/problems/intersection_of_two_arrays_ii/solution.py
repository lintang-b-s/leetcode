
"""
nums1 = [4,9,5], nums2 = [9,4,9,8,4]
c = { 4:1, 9: 1, 5:1  }
output=[]
buat pointer j =0
loop j<len(nums2) -1. jika elmeen ke j ada di c, maka tambahkan elemn ke j ke intersection dan counter elemen yg ditunjuk j dikurangi 1 karena intersection elemen yg ditunjuk j udah ada


"""
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c = Counter(nums1)
        intersection= []
        for n in nums2:
            if c[n] > 0:
                intersection.append(n)
                c[n] -=1
        return intersection
            
        
        
    
        
        
        