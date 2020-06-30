/* 

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8] 

*/

class Solution 
{
    public:
            vector<int> largestDivisibleSubset(vector<int>& nums) 
            {
                if(nums.size() == 0)
                    return nums;
                
                vector<int> ans;
                
                vector<int> prev(nums.size(), -1);
                vector<int> subset(nums.size(), 1);

                sort(nums.begin(),nums.end());
                
                int max_indx = 0;
                for(int i = 1 ; i < nums.size();i++) 
                {
                    for(int j = 0; j < i; j++) 
                    {
                        if(nums[i] % nums[j] == 0  && subset[i] < subset[j] + 1) 
                        {
                            prev[i] = j;
                            subset[i] = subset[j] + 1;
                        }
                    }

                    if(subset[i] > subset[max_indx])
                        max_indx = i;
                }

                int index = max_indx;
                
                while(index >=0) 
                {
                    ans.push_back(nums[index]);
                    index = prev[index];

                }
                return ans;
            }
};