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
1. bisa pakai pre order , visit root->rightChild->leftChild.
2. karena kita mengunjungi node paling kanan terdahulu di setiap level, untuk temukan right side node,  setelah node yang kita kunjungi berada di level yang lebih tinggi dari node sebelumnya , langsung masukkan node ke array result. 
3. setelah itu , jangan tambahkan node di result jika kita mengunjungi node di level yang pernah kita kunjungi sebelumnya.

ilustrasi/dry run: https://www.scaler.com/topics/images/the-recursive-algorithm.gif


*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int lastNodeResLevel=0;
        vector<int> result;
        int currLevel =1;
        rightSide(root, lastNodeResLevel, currLevel,result );
        return result;
    }
    
    void rightSide(TreeNode* node, int &lastNodeResLevel, int currLevel,  vector<int> &result){
        if (node == NULL){
            return ;
        }
        
        if ( lastNodeResLevel < currLevel) {
            result.push_back(node->val);
            lastNodeResLevel = currLevel;
        }
        
        rightSide(node->right, lastNodeResLevel, currLevel+1, result);
        rightSide(node->left, lastNodeResLevel, currLevel+1, result);
        
    }
    
};