/*

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.

 */

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int i,j,n,m;
        
        n = s.size();
        m = t.size();
        
        i=j=0;
        
        while(i<n and j<m)
        {
            if(s[i] == t[j])        // increment i pointer as we have found a match
                i++;
            
			if(i == n)              // checking whether we have found all the matches or not 
                return true;        // ( no need to check futher - optimization )
            j++;
        }
        
        return i == n;                // return whether we have found all the matches or not
    }
};