/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5*/

class Solution 
{
    public:
            int singleNonDuplicate(vector<int>& nums) 
            {
                int i = 0;
                int j = nums.size() - 1;

                while (i <= j) 
                {
                    int mid = i + (j - i) / 2;
                    
                    if (mid == 0 || mid == nums.size() - 1 || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])) {
                        return nums[mid];
                    }

                    int nextRoundHasOddNums = (mid - i) % 2;

                    if (nums[mid] == nums[mid - 1]) 
                    {
                        if (nextRoundHasOddNums) 
                        {
                            i = mid + 1;
                        } 
                        else 
                        {
                            j = mid - 2;
                        }
                    } 
                    else 
                    {
                        if (nextRoundHasOddNums) 
                        {
                            j = mid - 1;
                        } 
                        else 
                        {
                            i = mid + 2;
                        }
                    }
                }
                return -1;
            }
};