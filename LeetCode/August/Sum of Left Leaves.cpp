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
class Solution 
{
    public:
            void preorder(TreeNode *root, int &ans, TreeNode *parent)
            {
                if(root == NULL)
                    return;
                
                if(root->left == NULL && root->right == NULL && parent->left == root)
                    ans += root->val;
                
                preorder(root->left, ans, root);
                preorder(root->right, ans, root);
            }
            int sumOfLeftLeaves(TreeNode* root) 
            {
                if(root == NULL || (root->left == NULL && root->right == NULL))
                    return 0;
                
                int ans = 0;
                preorder(root, ans, NULL);
                return ans;
            }
};