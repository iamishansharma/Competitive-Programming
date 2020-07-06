/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.*/

class Solution 
{
    public:
        vector<int> plusOne(vector<int>& digits) 
        {
            int carry = 0;
            int n = digits.size();
            vector<int> ans(n+1);
            
            if(digits[n-1] == 9)
            {
                ans[n] = 0;
                carry = 1;
            }
            else
                ans[n] = digits[n-1] + 1;
            
            for(int i = n-2; i >= 0; i--)
            {
                if(digits[i] + carry == 10)
                {
                    ans[i+1] = 0;
                    carry = 1;
                }
                else
                {
                    ans[i+1] = digits[i] + carry;
                    carry = 0;
                }
            }
            
            if(carry == 1)
                ans[0] = 1;
            else
                ans.erase(ans.begin());
            
            return ans;
        }
};