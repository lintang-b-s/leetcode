func containsDuplicate(nums []int) bool {
    duplicateMap := make(map[int]bool , len(nums))
    for _, num := range nums{
        if _, found := duplicateMap[num]; found {
            return true
        }
        
        duplicateMap[num] = true
    }
    return false
    
}