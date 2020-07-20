/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.*/
class Solution 
{
    public:
            static bool comp(pair<int,int> a, pair<int,int> b) 
            {
                return a.second > b.second;
            }
            vector<int> topKFrequent(vector<int>& nums, int k) 
            {
                unordered_map<int, int> m;
                
                for(const auto &n: nums) 
                    ++m[n];
                
                vector<pair<int,int>> v(m.begin(), m.end());
                
                nth_element(v.begin(), v.begin() + k-1, v.end(), comp);
                
                vector<int> ans(k);
                
                for(int i{0}; i < k; ++i) 
                    ans[i] = v[i].first;
                
                return ans;
            }
};