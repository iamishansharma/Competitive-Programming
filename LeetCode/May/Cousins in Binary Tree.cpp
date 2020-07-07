/**
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

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
            void depth(TreeNode *root, int &d, int target, int h, TreeNode *&parent, TreeNode *tempp)
            {
                if(root == NULL)
                    return;
                
                if(root->val == target)
                {
                    d = h;
                    parent = tempp;
                    return;
                }
                
                tempp = root;
                
                depth(root->left, d, target, h+1, parent, tempp);
                depth(root->right, d, target, h+1, parent, tempp);
            }
    
            bool notsiblings(TreeNode *parent1, TreeNode *parent2)
            {
               if(parent1 == NULL || parent2 == NULL)
                    return false;
                
                if(parent1 == parent2)
                    return false;
                else
                    return true;
            }
    
            bool isCousins(TreeNode* root, int x, int y) 
            {
                int d1=0;
                int d2=0;
                
                TreeNode *p1 = NULL;
                TreeNode *p2 = NULL;
                
                depth(root, d1, x, 0, p1, NULL);
                depth(root, d2, y, 0, p2, NULL);
                
                if(d1 == d2 && notsiblings(p1, p2) == true)
                    return true;
                else
                    return false;
            }
};