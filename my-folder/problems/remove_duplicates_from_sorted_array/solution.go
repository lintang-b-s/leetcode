/*
    desc: buat dua pointer , i dan j. i untuk mennandakan elemen yg unik, dan j untuk mengiterasi array. Jika menemukan elemen unik maka tukar elemen yg ditunjuk i dg elemen yg ditunjuk j. dan geser pointer i kekanan
    
    if (nums[j] != nums[j+1])
    0<=j<=len(nums)-2
    
    1,1,2
    ij
    1,1,2
    i j
    1,1,2
      i    j
    1,1,2,
    
    1,2,2,
      i =1 +1
    
    
    
    
*/


func removeDuplicates(nums []int) int {
    i := 0
    for j:= 0 ; j<len(nums)-1; j++{
        if (nums[j] != nums[j+1]) {
            nums[i] = nums[j]
            i++
        }
    }
    
    nums[i] = nums[len(nums)-1]
    i++
    
    return i
    
    
}