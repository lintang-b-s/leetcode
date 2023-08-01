from typing import List

"""
[1,2,3,4,5,6,7] k =3

7,6,5,4,3,2,1
    i
5,6,7,1,2,3,4


"""


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k %len(nums)
        l, r = 0, len(nums) -1
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        self.kRotateSubArray(nums, 0, k)
        self.kRotateSubArray(nums, k, len(nums))

    def kRotateSubArray( self, nums: List[int], s: int, e:int) -> List[int]:

        l, r = s, e - 1
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        return nums

