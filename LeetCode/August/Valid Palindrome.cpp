/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.*/
class Solution 
{
    public:
            bool isPalindrome(string s) 
            {
                for (int i = 0, j = s.size() - 1; i < j; i++, j--) 
                {
                    while (isalnum(s[i]) == false && i < j) 
                    i++;
                    while (isalnum(s[j]) == false && i < j) 
                    j--;
                    
                    if(toupper(s[i]) != toupper(s[j]))
                        return false;
                }
                return true;
            }
};