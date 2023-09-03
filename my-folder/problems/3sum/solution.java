class Solution {
   public List<List<Integer>> threeSum(int[] nums) {
        HashSet<List<Integer>> res =  new HashSet<>();
        Arrays.sort(nums);
        int n = nums.length;

        for (int i = 0; i<n; i++){
            int l = i+1, r= n-1;
            int currNum = nums[i];
            while (l<r){
                if (currNum + nums[l] + nums[r] == 0 ){
                    List<Integer> sumZeroArray = new ArrayList<>();
                    sumZeroArray.add(currNum);
                    sumZeroArray.add(nums[l]);
                    sumZeroArray.add(nums[r]);

                    res.add(sumZeroArray);
                    l++;
                    r--;
                }
                else if (currNum + nums[l] + nums[r] < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>();
        result.addAll(res);
        return result;

    }
}