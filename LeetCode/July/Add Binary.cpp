/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.*/
class Solution 
{
    public:
            pair<char,int> getVal(int x,int y,int carry)
            {
                int val = x ^ y ^ carry;
                carry = (x+y+carry > 1) ? 1: 0;
                return {val+'0',carry};
            }
            string addBinary(string a, string b) 
            {
                string ans = "";
                int carry = 0;
                while(a.length() && b.length())
                {
                    auto p = getVal(a.back() - '0',b.back() - '0',carry);
                    carry = p.second;
                    ans+=p.first;
                    a.pop_back();b.pop_back();
                }
                while(a.length())
                {
                    auto p = getVal(a.back() - '0',0,carry);
                    carry = p.second;
                    ans+=p.first;
                    a.pop_back();
                 }
                while(b.length())
                {
                    auto p = getVal(0,b.back() - '0',carry);
                    carry = p.second;
                    ans+=p.first;
                    b.pop_back();
                }

                if(carry) ans+= '1';
                    reverse(ans.begin(),ans.end());

                return ans;
            }
};