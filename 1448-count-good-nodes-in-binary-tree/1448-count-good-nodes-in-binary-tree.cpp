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
1. pakai dfs preorder (root->left->right)
2. buat variabel maxVal , yg nilai awalnya root->val, diupdate setiap kali dfs dg nilai node yg lebih besar dari nilai maxVal.
3. buat variabel res utk menunjukkan jumlah good nodes. 
4. setiap dfs  , jika nilai node saat ini lebih besar dari nilai maxVal, tambahkan dg res dg angka 1, jika tidak tambahkan dg 0.

dry run:
     3
    / \
   1.  4
  /   / \
 3   1.  5


- dfs = 3, maxVal = 3, res = 0+1 = 1
- dfs = 1, maxVal = 1 <3 = 3 , res = 1+0 = 1
- dfs = 3, maxVal = 3>=3 = 3 , res = 1 + 1 =2
- dfs = 4, maxVal = 4 >=3 = 3, res = 2+1 = 3
- dfs = 1, maxVal = 1 <=4 = 4 , res = 3+0
- dfs=. 5, maxVal = 5 >= 4=. 5, res = 3+1 = 4 
backtrack
return 4




*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        int res = dfs(root, root->val);
        return res;
    }
    
    int dfs(TreeNode* root, int nodeVal) {
        if (root == NULL){
            return 0;
        }
        
        int res = 0;
        if (root->val >=  nodeVal){
             res = 1;
        } 
        
        int maxVal = max(root->val , nodeVal);
        
        res += dfs(root->left, maxVal);
        res += dfs(root->right, maxVal);
        return res;
    }
};