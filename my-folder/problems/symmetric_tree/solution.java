/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/*

        1
      /   \
     2     2
    /\    / \
   3  4   4  3


recursive
1 is equal 1
l          r
 2 is equal 2   && 2 is equal 2
  l         r      r          l
 3     is equal 3           &&  4 is equal 4
 l.l           r.r               l.r          r.l

null    null &&  null null   &&  null    null &&  null   null
 l.l.l  r.r.r   l.l.r  r.r.l     l.r.l    r.l.r    l.r.r r.l.l

*/
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return dfs(root, root);

    }

    public boolean dfs(TreeNode left, TreeNode right){
        if (left == null && right == null){
            return true;
        }
        if (left == null || right == null || left.val != right.val){
            return false;
        }
        
        return dfs(left.left, right.right) && dfs(left.right , right.left);
    }
}