/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
            vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
            {
                vector<vector<int>> res;
                if(root== NULL)
                    return vector<vector<int>>();
                queue<TreeNode*> q;
                q.push(root);
                int f = false;
                while(q.size())
                {
                    int size = q.size();   //Get size of each level. (beginning with 1 for root)
                    vector<int> level;
                    while(size--)
                    {
                        TreeNode* curr = q.front();
                        level.push_back(curr->val);   //Push prev level's node into array.
                        q.pop();
                        if(curr->left)
                        {
                            q.push(curr->left);  // Adding left node (if present) into new level.
                        }
                        if(curr->right)
                        {
                            q.push(curr->right);  // Adding right node (if present) into new level.
                        }

                    }
                    if(f)        //Reverse every alternate level
                     reverse(level.begin(),level.end());
                    f=!f;   //toggling
                    res.push_back(level);
                }
                return res;
            }
};