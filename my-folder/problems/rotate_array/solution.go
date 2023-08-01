package main

import "fmt"

func rotate(nums []int, k int) []int {
	n := len(nums)
	k = k % n

	reversed := kRotateSubArray(nums, 0, len(nums))

	kRotateSubArray(reversed, 0, k)
	kRotateSubArray(reversed, k, len(nums))
	return reversed
}

func kRotateSubArray(nums []int, s int, e int) []int {
	l, r := s, e-1
	for l < r {
		nums[l], nums[r] = nums[r], nums[l]
		l += 1
		r -= 1
	}
	return nums
}