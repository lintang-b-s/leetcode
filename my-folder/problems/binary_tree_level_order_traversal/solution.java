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
      9   20
         15  7
         
queue = [3] -> arr =  [[]]
queue = [9,20] -> arr =  [[3]]
queue = [20] -> arr =  [[3], [9,]
queue = [15,7] -> arr =  [[3], [9,20], ]
queue = [7] -> arr =  [[3], [9,20], [15]]
queue = [] -> arr =  [[3], [9,20], [15,7]]

*/

class Solution {
 public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> level=  new ArrayList<>();

        if (root == null){
            return level;
        }
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);




        while (!q.isEmpty()){
           int currentLength = q.size();

           List<Integer> newLevel = new ArrayList<>();
           
           for (int i = currentLength; i>0 ; i--){
               TreeNode node=  q.poll();
                newLevel.add(node.val);
               if (node.left !=null){
                   q.add(node.left);
               }
               if (node.right !=null){
                   q.add(node.right);

               }
           }
           level.add(newLevel);
        }
        return level;

    }
}