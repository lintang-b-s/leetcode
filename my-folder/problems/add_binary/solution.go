package main

import (
	"fmt"
	"strconv"
)

/*
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
*/

func addBinary(a string, b string) string {
	i, j := len(a)-1, len(b)-1
	carry := 0
	result := ""
	for i >= 0 || j >= 0 || carry == 1 {
		sum := carry
		if i >= 0 {
			an, _ := strconv.Atoi(string(a[i]))
			sum += an
		}
		if j >= 0 {
			an, _ := strconv.Atoi(string(b[j]))
			sum += an
		}
		result = strconv.Itoa(sum%2) + result
		carry = sum / 2
		i--
		j--

	}
	return result
}