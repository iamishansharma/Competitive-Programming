/*Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

class Solution 
{
    public:
            
            vector<int> FindSubsets(int binum, vector<int> nums)
            {
                vector<int> ans;
                int i=0;
                while(binum)
                {
                    if(binum & 1)
                    {
                        ans.push_back(nums[i]);
                    }
                    i++;
                    binum >>= 1;
                }
                return ans;
            }
    
            vector<vector<int>> subsets(vector<int>& nums) 
            {
                vector<vector<int>> ans;
                
                int total = 1<<nums.size();
                
                for(int i=0; i<total; i++)
                {
                    vector<int> temp = FindSubsets(i, nums);
                    ans.push_back(temp);
                }
                return ans;
            }
};