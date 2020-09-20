class Solution 
{
    public:
            bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
            {
                set<long> window;

                for (int i = 0; i < nums.size(); ++i) 
                {
                    long n = nums[i];

                    if (i > k)
                        window.erase(nums[i-k-1]);

                    auto pos = window.lower_bound(n - t);

                    if (pos != window.end() && (*pos - n) <= t)
                        return true;

                    window.insert(n);
                }
                return false;
            }
};