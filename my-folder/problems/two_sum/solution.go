/*
hashmap = {2: 0}
[2,7,11,15] target = 9
 i             elemen selain i yg dijumlah = target -> taget- nums[i]
(9-2)

[2,7,11,15]
   i
(9-7) return [map[2], i]

 */



func twoSum(nums []int, target int) []int {
	newMap := make(map[int]int)
	for i, n := range nums {
		other := target - n
		if value, ok := newMap[other]; ok {
			return []int{value, i}
		}
		newMap[n] = i
	}

	return []int{}
}