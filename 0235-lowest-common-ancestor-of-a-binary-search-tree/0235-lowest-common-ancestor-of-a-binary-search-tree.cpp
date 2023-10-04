/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 karena binary search tree sifatnya node->left < node->data dan node->right > node->data.  lca nya ada di shared ancestor yg paling dekat dengan n1 dan n2 / paling jauh dg root node. Unutk mencari ancestor paling dekat dg n1 dan n2 bisa dg membandingkan node->data leftChild dan rightChild , jika n1 dan n2 lebih kecil dari node->data berarti lca mungkin ada di left dari node. Jika n1 dan n2 lebih besar dari node->data berarti lca mungkin ada di right dari node. Jika keduanya tak dipenuhi berarti node merupakan ancestor terrdekat dg n1 dan n2 
 

dry run:
`       20
       /  \
      8.  22
     /\.   
    4  12
       / \
      10. 14

n1=10 , n2=14
10 < 20 && 14 <20 -> ambil subtree kiri
10 > 8 && 14 > 8 -> ambil subtree kanan
10 < 12 && 14 >12 ->  return root (root = 12) 



 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL){
            return NULL;
        }
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if (p->val< root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};