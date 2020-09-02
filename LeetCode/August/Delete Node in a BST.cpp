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
            TreeNode* deleteNode(TreeNode* root, int key) 
            {
                if(root == NULL)
                    return NULL;
                
                if(root->val == key) 
                {
                    TreeNode* new_root;
                    
                    if (root->left != NULL && root->right != NULL) 
                    {
                        new_root = root->right;
                        
                        while (new_root->left != NULL)
                            new_root = new_root->left;
                        
                        new_root->left = root->left;
                        new_root = root->right;
                        
                    } 
                    else if(root->left != NULL) 
                        new_root = root->left;
                    else if(root->right != NULL)
                        new_root = root->right;
                    
                    delete root;
                    return new_root;
                }
                
                if (root->val > key) 
                    root->left = deleteNode(root->left, key);
                else 
                    root->right = deleteNode(root->right, key);
                
                return root;
            }
};