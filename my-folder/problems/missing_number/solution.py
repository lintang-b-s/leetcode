
"""
Input: nums = [3,0,1]
n = len(nums) = 3
Output: 2
karena array isinya angka menaik maka dan hanya satu elemen yg hilang, maka bisa pakai rumus  n*(n+1)/2 - sum(nums)
jumlah seharusnya = 1 + 2 + 3 = 6
jumlah di arraynya = 0 + 3 + 1 = 4
yg hilang = 6-4 =2
Time complexity : O(n)
Space Complexity: O(1)


"""


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        intendedSum = n*(n+1)//2
        sumNum = sum(nums)
        return intendedSum-sumNum