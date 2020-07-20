/*Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].*/
class Solution {
public:
    
    bool isEqual(int *a, int *b) {
        for(int i=0; i<26; i++)
            if(a[i]!=b[i])
                return 0;
        return 1;
    }
    
    bool checkInclusion(string s2, string s1) {
        int hm[26], hm2[26];
        memset(hm,0,sizeof hm);
        memset(hm2,0,sizeof hm2);
        int n = s1.size(), k =s2.size();
        if(k > n)
            return 0;
        for(char a : s2)
            hm[a-'a']++;
        for(int i=0; i<k; ++i) {
            hm2[s1[i]-'a']++;
        }
        if(isEqual(hm2, hm))
            return 1;
        for(int i=0, j=k; j <n; j++, i++) {
            hm2[s1[i]-'a']--;
            hm2[s1[j]-'a']++;
            if(isEqual(hm2, hm))
                return 1;
        }
        return 0;
    }
};