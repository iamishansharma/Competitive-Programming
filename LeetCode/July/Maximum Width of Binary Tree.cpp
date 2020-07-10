/**
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
            int widthOfBinaryTree(TreeNode* root) 
            {
                int ans = 0;

                queue<pair<TreeNode*, unsigned long long>> q;

                if (root)
                    q.push({root, 1});

                while (!q.empty()) 
                {
                    int qsize = q.size();

                    unsigned long long left = q.front().second, right;

                    while(qsize--) 
                    {
                        TreeNode* n = q.front().first;
                        right = q.front().second;
                        q.pop();

                        if (n->left != nullptr) 
                            q.push({n->left, 2*right});
                        if (n->right != nullptr)
                            q.push({n->right, 2*right+1});
                    }
                    ans = max(ans, (int)(right - left + 1));
                }

                return ans;
            }
};