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
- level order traversal pakai bfs.
- setiap level add setiap elemen di level tsb ke inner array. ganti level tree saat queue nya habis isinya.
- setiap kali pop elemen dari queue add elemen ke array


dry run:

        3
       / \ 
      9   20
         /  \
        15.  7

1. 
queue= 3 
pop 3 -> [[3]], queue= []
push 9., 20 -> queue = [9,20]

2. queue = [9,20]
pop 9 -> [[3], [9]], queue = [20]
pop 20 -> [[3], [9,20]], queue =[]
push  15,7 -> queue= [15,7]

3.  queue= [15,7]
pop 15 -> [[3], [9,20], [15]] , queue =[7]
pop 7 -> [[3], [9,20], [15, 7]], queue = []

-- [[3], [9,20], [15, 7]]


time complexity: O(n) , visit setiap node 1x
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> result;

        if (root == NULL){
            return result;
        }
        queue.push(root);
        int ans= 0;
        
        
        while (!queue.empty()){
            int currentQueueLength = queue.size();
            
            vector<int> currLevel;
            for (int i=0; i<currentQueueLength; i++){
                TreeNode* node = queue.front();
                queue.pop();
                
                currLevel.push_back(node->val);
                if (node->left != NULL){
                    queue.push(node->left);
                }
                if (node->right != NULL){
                    queue.push(node->right);
                }
            }
            
            result.push_back(currLevel);
        }
        return result;
    }
};