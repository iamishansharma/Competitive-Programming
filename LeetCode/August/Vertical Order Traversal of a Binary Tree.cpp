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
	struct comp
    {
		bool operator()(const pair<int, int>& x, const pair<int, int>& y)
        {
			if(x.first == y.first)
				return x.second > y.second;
            
			return x.first > y.first;
		}
	};

	vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
       	//	width                   value level
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> hash;
        
        // 			node          width level
		queue<pair<TreeNode*, pair<int, int>>> bfs;
		bfs.push({root, {0, 0}});
        
		pair<TreeNode*, pair<int, int>> curr;

		while(!bfs.empty())
        {
			curr = bfs.front();
			bfs.pop();

			hash[curr.second.first].push({curr.second.second, curr.first->val});

			if(curr.first->left) 
				bfs.push({curr.first->left, {curr.second.first - 1, curr.second.second + 1}});
			if(curr.first->right) 
				bfs.push({curr.first->right, {curr.second.first + 1, curr.second.second + 1}});
		}

		vector<vector<int>> result;
		vector<int> temp;

		for(auto itr : hash)
        {
			while(!itr.second.empty())
            {
				temp.push_back(itr.second.top().second);
				itr.second.pop();
			}
			result.push_back(temp);
			temp.clear();
		}

		return result;
	}
};