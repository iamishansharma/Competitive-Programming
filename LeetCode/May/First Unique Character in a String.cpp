/*Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.*/

class Solution 
{
    public:
            int firstUniqChar(string s) 
            {
                int alphabets[26] = {0};
                
                for(int i=0; i<s.length(); i++)
                    alphabets[s[i]-'a']++;

                for(int i=0; i<s.length(); i++)
                    if (alphabets[s[i]-'a']==1) 
                        return i;

                return -1;
            }
};