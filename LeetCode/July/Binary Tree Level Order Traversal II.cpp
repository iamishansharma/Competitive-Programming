/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
            vector<vector<int>> levelOrderBottom(TreeNode* root) 
            {
                if(root == NULL)
                    return vector<vector<int>> ();
                
                vector<vector<int>> ans;
                
                queue<TreeNode *> q;
                q.push(root);
                
                stack<vector<int>> st;
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    
                    vector<int> temp;
                    
                    while(qsize--)
                    {
                        TreeNode *t = q.front();
                        q.pop();
                        
                        temp.push_back(t->val);
                        
                        if(t->left != NULL)
                            q.push(t->left);
                        if(t->right != NULL)
                            q.push(t->right);
                    }
                    
                    st.push(temp);
                }
                
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                
                return ans;
            }
};