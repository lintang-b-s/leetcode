
"""

[5,7,7,8,8,10]

l =0, r= 5
len = 6, mid = 2
mid = l + (r -l)/2
target = 8
5,7,7,8,8,10
l   m     r -> nums[m] < target
5,7,7,8,8,10
      l m r -> m==target , nums[m-1] != target
5,7,7,8,    8,10
      lrm
5,7,7,8,    8,10
      lmr ,  m ==target , nums[m-1] != target {return nums[m]}

                            nums[m+1] != target return nums[mid]
5,7,7,8,8,10
      l m r

"""
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = self.findFirstOccurence(nums, target)
        last = self.lastOccurence(nums, target)

        return [first, last]

    def findFirstOccurence(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <=r :
            mid = l + (r-l ) //2
            if (nums[mid] == target):
                if (mid == 0 or nums[mid-1] != target) :
                    return mid
                r = mid-1
            elif (nums[mid] > target):
                r = mid - 1
            else:
                l = mid + 1
        return -1

    def lastOccurence(selfself, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l)// 2
            if (nums[mid] == target):
                if (mid == len(nums)-1 or nums[mid + 1] != target):
                    return mid
                l = mid +1
            elif (nums[mid] > target):
                r = mid - 1

            else:
               l = mid +1
        return -1