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
lakukan post order traversal


setiap kunjungi node, hitung maxDiameter ,height , leftHeight, RightHeight, Diamter.
Dia= diamter
maxDia= max(maxDia, Dia).
height = max(left, right) + 1

dry run/ilustrasi:
https://lh6.googleusercontent.com/K9DIkgZTNDrX5ZoBtx2Y0_mCzn0Bz02VvC3eVrmlSLoU3YT4tNvncAhIydWHKzuhOm3jF6-Bm_oACtukx8NpzNSJOf9X6ZacboQpiSJJ0baA6vojo54-tIE2iRYDNjssPtMBFK78



 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }
    
    int calculateDiameter(TreeNode* node, int& diameter){
        if (!node){
            return 0;
        }
        int leftHeight= calculateDiameter(node->left, diameter);
        int rightHeight= calculateDiameter(node->right, diameter);
        
        diameter = max(diameter,  leftHeight+ rightHeight);
        return 1 + max(leftHeight, rightHeight);

    }

};