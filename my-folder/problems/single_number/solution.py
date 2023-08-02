
"""
2,2,1
ij 
2,2,1
i j
2,2,1
i


4,1,2,1,2
ij
4,1,2,1,2
i      



"""

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result ^= num
        return result
        