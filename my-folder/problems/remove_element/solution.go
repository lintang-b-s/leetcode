/*
j =0
3,2,2,3 val =3
ji
3,2,2,3
  i
2,2,2,3
  ji
2,2,2,3
  j i
2,2,2,3
  j i
2,2,2,3
    j i
2,2,2,3 

*/

func removeElement(nums []int, val int) int {
    j := 0
    for i := 0; i < len(nums); i++ {
        if (nums[i] != val){
            nums[j] = nums[i]
            j++
        }

    }
    return j
}