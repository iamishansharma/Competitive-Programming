/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.*/
class Solution 
{
    public:
            bool canConstruct(string ransomNote, string magazine) 
            {
                unordered_map<char, int> m;
                
                for(int i=0; i<magazine.size(); i++)
                    m[magazine[i]]++;
                
                for(int i=0; i<ransomNote.size(); i++)
                {
                    if(m[ransomNote[i]] > 0)
                        m[ransomNote[i]]--;
                    else
                        return false;
                }
                return true;
            }
};