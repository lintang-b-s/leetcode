
class Solution:
    """
    1,2,3,1

    hash = {1:0, 2:0, 3:0}

    1,2,3,1
    i
    hash {1:1,2:0, 3:0}
    1,2,3,1
      i
    hash {1:1,2:1, 3:0}
    1,2,3,1
        i
    hash {1:1,2:1, 3:1}
    1,2,3,1
          i
    hash {1:2,2:1, 3:1}
    
    
    sol 2 hashset
    
      1,2,3,1

    hash = {1:0, 2:0, 3:0}

    1,2,3,1
    i
    hash {1:1,2:0, 3:0}
    1,2,3,1
      i
    hash {1:1,2:1, 3:0}
    1,2,3,1
        i
    hash {1:1,2:1, 3:1}
    1,2,3,1
          i
    hash {1:2,2:1, 3:1}
    return True

    """

    def containsDuplicate(self, nums: List[int]) -> bool:
        numDict = set()
        for num in nums:
            if num in numDict:
                return True
            numDict.add(num)
            
        return False

        
        
        