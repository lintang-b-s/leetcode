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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;

        if (!root){
            return res;
        }
        queue.push(root);

        bool kiriKeKanan = false;

        while (!queue.empty()){
            int currLevelQueue= queue.size();

            vector<int> currLevel;

            for (int i=0; i < currLevelQueue; i++){
                TreeNode* currNode = queue.front();
                queue.pop();

                currLevel.push_back(currNode->val);
              
                if (currNode->left != nullptr){
                queue.push(currNode->left);
                }
                if (currNode->right != nullptr){
                    queue.push(currNode->right);
                }
                
            }
            kiriKeKanan = !kiriKeKanan;
            if (kiriKeKanan == false){
                reverse(currLevel.begin(), currLevel.end());
            }   

            res.push_back(currLevel);
        }

        return res;
    }
};


/*
Time Complexity: O(n)

*/