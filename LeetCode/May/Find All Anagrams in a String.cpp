/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

class Solution 
{
    public:
            void modify(unordered_map <char, int> &v, char k, bool ok)
            {
                if(v.find(k)==v.end()) 
                    v[k] = 0;
                v[k] += ok ? 1 : -1;
                if(!v[k])
                    v.erase(k);
            }
            vector<int> findAnagrams(string s, string p) 
            {
                unordered_map <char, int> v;
                vector <int> ans;
                int N = p.length();
                
                for(char c:p)
                    modify(v, c, true);
                
                for(int i=0;s[i];++i)
                {
                    modify(v, s[i], false);
                    
                    if(i>=N)
                        modify(v, s[i-N], true);
                    if(v.empty())
                        ans.push_back(i-N+1);
                }
                return ans;
            }
};