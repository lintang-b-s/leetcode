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

ilustrasi = https://share.sketchpad.app/23/d2b-b32e-f65110.png

 */
class Solution {
public:
    int maxPath = 0;
    int longestZigZag(TreeNode* root) {
        bool kiriKeKanan = true;
        dfs(root, false, 0);
        dfs(root,true, 0);
        return maxPath;
    }   

    void dfs(TreeNode* root, bool canGoRight,
               int currLength ){
       if (root == nullptr){
           return;
       }
       maxPath = max(maxPath, currLength);
       if (canGoRight){
           // sebelumnya left child
            dfs(root->right, false, currLength+1);
            dfs(root->left, true, 1);
        
       }else {
           // sebelumnya ke right child
              dfs(root->left, true, currLength+1);
           dfs(root->right, false, 1);
       }
    }
};