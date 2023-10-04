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
    jika root == null ,maka false, karena jelas subrot bukan subroot dari root
    
    cek same tree bisa dg cek secara recursive setiap  node dari tree , base case nya kedua nodenya null (berarti salah satu sisi child dari kedua tree sama )
 

*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL){
            return false;
        }if (isSameTree(root, subRoot)){
//             jika tree root dan subroot sama
            return true;
        }
//         cek di child dari root node  apakah sama dg subroot
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
    private:
        bool isSameTree(TreeNode* root, TreeNode* subRoot){
            if (root == NULL && subRoot == NULL){
//                  keduanya null  -> return true
                return true;
            }
            if (root == NULL || subRoot == NULL){
                return false;
            }
            if (root->val != subRoot->val){
                return false;
            }
//             jika node punya value , maka cek child nodenya 
            return isSameTree(root->left, subRoot->left) &&
                isSameTree(root->right, subRoot->right);
        }
};