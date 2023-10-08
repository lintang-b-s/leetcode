



class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curNode =  new ArrayList<Integer>();
        backtrack(0, candidates, target, curNode, res);
        return res;
    }

    private void backtrack(int s, int[] candidates, int target, List<Integer> curNode,
                   List<List<Integer>> ans) {
    if (target < 0)
      return;
    if (target == 0) {
      ans.add(new ArrayList<>(curNode));
      return;
    }

    for (int i = s; i < candidates.length; ++i) {
      curNode.add(candidates[i]);
      backtrack(i, candidates, target - candidates[i], curNode, ans);
      curNode.remove(curNode.size() - 1);
    }
  }
}