/*Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.*/class Solution 
{
    public:
            int findMaxLength(vector<int>& nums) 
            {
                int sum=0;
                unordered_map<int,int> m;
                int ans = 0;

                for(int i=0;i<nums.size();i++)
                {
                    sum += (nums[i] == 0) ? -1:1;

                    auto it = m.find(sum);

                    if(sum == 0)
                        ans = max(ans, i+1);
                    else if(it != m.end())
                        ans = max(ans, i-it->second);
                    else if(it == m.end())
                        m.insert({sum,i});
                }
                return ans;
            }
};