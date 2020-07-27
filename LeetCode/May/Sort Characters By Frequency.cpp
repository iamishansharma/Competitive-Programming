/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

bool cmp(pair<int,char>& a,pair<int,char>& b)
{
    return a.first > b.first;
}

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char,int>m;

        for(int i=0; s[i]; i++)
            m[s[i]]++;

        vector<pair<int,char> > v;
        for(auto itr : m)
            v.push_back({itr.second,itr.first});
            
        sort(v.begin(),v.end(),cmp);

        string res = "";
        for(int i=0,n = v.size(); i<n; i++)
        {
            while(v[i].first--)
                res += v[i].second;
        }

        return res;
    }
};