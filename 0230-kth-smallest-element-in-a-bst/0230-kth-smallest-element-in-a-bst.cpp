
/*
intuisi:
1. bst jika di inorder traversal urutannya selalu increasing menaik
2. buat variabel counter= 0, setiap kali visit node  increemnt counter, jika counter == k return node->val

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        int ans = -1;
         dfs(root, k, c, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int k,int& c , int& ans) {
        if (root == nullptr) {
            return ;
        }
        dfs(root->left, k, c, ans);
        if (++c == k){
            ans= root->val;
            return ;
        }

        dfs(root->right, k, c, ans);
       
    }
};