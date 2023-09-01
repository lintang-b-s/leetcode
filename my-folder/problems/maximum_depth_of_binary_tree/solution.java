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

        3
    9        20
 n    n   15     7

       null         null


queue = 3, null
        null, 9, 20       depth = 0, current = 3
        9, 20  , null     depth = 1,  current = null
        20, null          depth = 1, current=  9
        null, 15, 7          d=1             current=20
        15, 7 , null       current = null, depth = 2,
        7, null depth  = 2, current=  15
        null current = 7, depth = 2
                current=  nulll, depth = 3

*/
class Solution {
    public int maxDepth (TreeNode root){
        if (root == null){
            return 0;
        }
        Queue<TreeNode> q=  new LinkedList<>();
        q.offer(root);
        q.offer(null);
        int depth = 0;
        
        while (!q.isEmpty()){
            TreeNode curr = q.poll();
            
            if (curr == null){
                
                depth ++;
                if (!q.isEmpty()){
                    q.offer(null);
                }
                continue;
            }
            
            if (curr.left != null){
                q.offer(curr.left);
            }
            if (curr.right != null){
                q.offer(curr.right);
            }
        }
        
        return depth;
    }
}