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
penjelasan:
misal input:
        5
       / \
      4   8
     /   / \
    11  13 4
   / \      \
  7   2      1

5+4+11+2
setiap memanggil fungsi rekursi dfs ke child node left/right nilai sum dikurangi dg nilai root.val
jika root.val == 0 return true
jika   sum menjadi 0 di salah satu child node return true



*/
class Solution {
   public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null){
            return false;
        }

        if (root.left == null && root.right == null && targetSum - root.val == 0){
            return true;
        }

        return hasPathSum(root.left, targetSum - root.val) ||
                hasPathSum(root.right, targetSum-root.val);
    }
}