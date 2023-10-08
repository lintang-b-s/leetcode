

/*

nums =[2,1 , 1] => [1,2,2]

                      [] 
                /.              \
            [2]                 [1]  
            /   \             /.     \
          [2]    [2,2]        [1]         [1.2]    
                            /          /     \ 
                          [1]      [1,2]  [1,2,2]   
                      

subset= [] - [1]-[1,2]-[1,2,2] - [1,2] - [1] - [1,2] (ignore) - [2] - [2,2]- [2] - []  ?
 idx=         0   1     2 /3       2      1     2               0/1    2      2     
 i=.          0.  1     2/3       2,3     1.    2               1      2      2    
res=. [[], [1], [1,2], [1,2,3], ..., [2] , [2,2]]
idx=.  0.   1.    2      3           
*/

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        Arrays.sort(nums);
        backtrack(nums, res, 0 , new ArrayList<>());
        return res;
    }
    
    public void backtrack(int[] nums,   List<List<Integer>> res , int index, List<Integer> subSet)      {
       res.add(new ArrayList<>(subSet));
        
       for (int i =index ; i < nums.length ; ++i){
           if (i > index && nums[i] == nums[i-1]){
               continue;
           }
           subSet.add(nums[i]);
           backtrack(nums, res, i+1, subSet);
           subSet.remove(subSet.size()- 1);
       }
        
    }
}