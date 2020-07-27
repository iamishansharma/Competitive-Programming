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
        unordered_map<int,int> m;

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
        {
            for(int i=0;i<inorder.size();i++)
                m[inorder[i]] = i;
            
            int rootIndex = postorder.size()-1;
            
            return buildUtil(inorder,postorder,0,inorder.size()-1,rootIndex);
        }
    
    TreeNode* buildUtil(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int &rootIndex)
    {
        if(inleft > inright)
            return NULL;
        
        int val = postorder[rootIndex];
        TreeNode *node = new TreeNode(val);
        rootIndex--;
        
        if(inleft==inright)
            return node;
        
        int pivot=m[val];
        
        node->right = buildUtil(inorder, postorder, pivot + 1, inright, rootIndex); 
        node->left = buildUtil(inorder, postorder, inleft, pivot - 1, rootIndex); 
  
        return node; 
    }
};