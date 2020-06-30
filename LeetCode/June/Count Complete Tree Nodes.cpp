/**

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

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
            int countNodes(TreeNode* root) 
            {
                if(root == NULL)
                    return 0;
                
                //recursive

                int hl=0, hr=0;

                TreeNode *l = root, *r = root;

                while(l) 
                {
                    hl++;
                    l=l->left;
                }

                while(r) 
                {
                    hr++;
                    r=r->right;
                }

                if(hl==hr) 
                    return pow(2,hl)-1;

                return 1 + countNodes(root->left) + countNodes(root->right);
                
                //iterative, level order
                
                /*queue<TreeNode *> q;
                q.push(root);
                
                int count = 0;
                
                while(!q.empty())
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    
                    count++;
                    
                    if(temp->left != NULL)
                        q.push(temp->left);
                    
                    if(temp->right != NULL)
                        q.push(temp->right);
                }
                
                return count;*/
            }
};