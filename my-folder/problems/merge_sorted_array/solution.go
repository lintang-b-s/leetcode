
/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

cara 2
l = m+n-1 (elemen terakhir dari nums1)

[1,2,3,0,0,0]
     m     l   6>3 nums2[n] > nums1[m], set nums1[l] = nums2[n], geser l ke kiri, geser n kekiri

[1,2,3,0,0,6]
     m   l     5>3
[1,2,3,0,5,6]
     m l      2< 3, nums2[n] < nums1[m], set nums1[l] = nums1[m], geser m  ke kiri , geser l ke kiri
[1,2,0,3,5,6]
   m l		2 == 2, set nums1[l]=nums2[n], geser  l ke kiri, geser n ke kiri
[1,2,2,3,5,6]
   ml


[2,5,6]
     n
[2,5,6]
   n
[2,5,6]
 n
n=-1



*/

func merge(nums1 []int, m int, nums2 []int, n int)  {
	l := m+n-1
	for m > 0 && n >0 {
	
		if nums2[n-1] >= nums1[m-1] {
			
			nums1[l] = nums2[n-1]
			n--
		} else {
			nums1[l] = nums1[m-1]
			m--
		}
		l--
	}
	for ; n > 0; n-- {
		nums1[n-1] = nums2[n-1]
	}

}