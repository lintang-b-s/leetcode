"""
 c: 11     carry = sum / 2 res = sum%2
     11
      1
    ---
    100

 1 1 1 1  sum = carry=0
 1 1 0 1.  result = ""  ,  setiap iterasi result.appendLeft(res)
       ji  sum= 0+1+1 = 2, res= 0, carry = 1,  result = "0"
     ij sum = carry + a[i] + b[j] = 1 + 1 + 0 = 2, res = 0, carry = 1, result = " 00"
   ij sum = 1 + 1 + 1 = 3, res = 1, carry = 1       result = "100"
 ij sum = 1 + 1 + 1= 3, res =1, carry =1,    result = "1100"
 

buat elemen carry =0 , iterasi  pake pointer i sama j selama i j lebih dari sama dengan 0. set sum ke nilai carry, tambahkan sum dg nilai yg ditunjuk pointer i sama j. hitung res dg rumus  res = sum%2, hitung sum dg rumus carry = sum / 2

Time Complexity: O(n)
Space Complexity: O(n)


"""

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) -1, len(b) - 1
        carry = 0
        result = ""
        while (i >=0 or j >=0  or carry ==1 ):
            sum = carry
            if (i >= 0):
                sum += int(a[i])
            if (j >=0):
                sum += int(b[j])
            result =  str(sum%2) + result
            carry = sum//2
            i -=1
            j -=1
        return result


       





