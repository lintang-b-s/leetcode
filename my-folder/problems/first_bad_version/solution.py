# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

"""
    isBadVersion(version: int) -> bool{
        if (version >=3) {
            return True
        }
        return False
    }

    Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
 while (l <r)
 mid = (l +r )/2 = l + (r-l)/2

 1 2 3 4 5
 l   m   r. isBadVersion(3) -> false
 1 2 3 4  5
       ml r isBadVersion(4) -> true
  r = m
 1 2 3 4   5
       rlm
return l
 4


"""

class Solution:
    def firstBadVersion(self, n: int) -> int:
        if (n == 1):
            return 1
        
        l, r  = 1, n 
        while( l< r):
            mid = (l+r)//2
            if ( isBadVersion(mid)): r=  mid
            else: l = mid + 1
        return l


