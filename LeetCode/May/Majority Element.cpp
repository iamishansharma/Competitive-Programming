/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/

class Solution 
{
    public:
        int majorityElement(vector<int>& a) 
        {
            int size = a.size();
            int maj_index = 0, count = 1; 
            for (int i = 1; i < size; i++) 
            { 
                if (a[maj_index] == a[i]) 
                    count++; 
                else
                    count--; 
                if (count == 0) 
                { 
                    maj_index = i; 
                    count = 1; 
                } 
            } 
            return a[maj_index];
        }
};