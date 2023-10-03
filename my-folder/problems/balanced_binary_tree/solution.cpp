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
impl: pakai postorder traversal. traverse left dan right subtree, lalu parent node.  
1. traverse postorder
2. setiap call hitung height dari current node dan return ke call sebelumnnya
3. saat call di setiap node, cek apakah kondisi balance binary tree terpenuhi.
4. jika tidak return -1 ke call sebelumnya. jika terpenuhi return height dari current node ke call sebelumnya

height dari current node = (leftHeight + rightHeight) +1

dry run: https://lh5.googleusercontent.com/YUgvNXC0goaXh7Rn7HUgjBeSKUFBCIBY5-Mpd2AD1MNLIeMBjIeMnKVq1kPcyWw8kvPGdqCG8KoislWJ6QRlapKP1nkqW7mln0LDBcfh5PB0N0T9b-cnUu2rR-O4usEFjFB-0ASg

 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode *node){
        if (node==NULL){return 0;}
        int leftHeight = dfsHeight(node->left);
        if (leftHeight == -1){
            return -1;
        }
        int rightHeight= dfsHeight(node->right);
        if (rightHeight == -1){
            return -1;
        }
        if (abs(rightHeight-leftHeight) >1){
            return -1;
        }
        return max(leftHeight, rightHeight) +1;
    }
};