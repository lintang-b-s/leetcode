/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
intuisi:


dry run:

    2
   / \ 
  1.  3


dfs= 2, 2 > INT_MIN & 2 < INT_MAX -> maxVal = 2 -> next dfs
dfs = 1, 1 > INT_MIN & 1 < maxVal =2 -> minVal = 1 ->next dfs
minVal = 2
dfs = 3, 3 > minVal = 2, 3 < INT_MAX -> 
dfs= null -> return true.


case 2:
      5
     / \
    1.  4
       / \
      3.  6

dfs= 5, 5 > INTMIN , 5 < INTMAX -> maxVal=5 -> next dfs
dfs = 1, 1 > INTMIN, 1 < 5 -> minVal = 1 ->next dfs
minVal = 5 
dfs = 4, 4 < minVal = 5 return false
*/
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return dfs(root, nullptr, nullptr);
  }

 private:
  bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (root == nullptr)
      return true;
    if (minNode && root->val <= minNode->val)
      return false;
    if (maxNode && root->val >= maxNode->val)
      return false;

    return dfs(root->left, minNode, root) &&
           dfs(root->right, root, maxNode);
  }
};