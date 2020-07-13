/*Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/

class Solution 
{
		public:
						string removeKdigits(string num, int k) 
						{
								stack<char> s; 
								int i=0;

								// 1. First we iterate throught the string and store it in the stack
								//    If at any point the value of the character is less than top of the stack 
								//    We delete all elements of stack greated than this value. 
								 //   We stop when top of stack is less than the current element(num[i]), push the character onto the stack and continue our iteration
								// The iteration stops when k is 0 or all elements of num have been iterated
							 while (k && i<num.size())
							 {
									 if (!s.size()) 
										s.push(num[i++]);
									 else 
									 {
											 if(num[i] < s.top()) 
											 {
													 while(s.size() && k) 
													 {
															if(num[i] < s.top()) 
															{
																	s.pop();
																	k--;
															} 
															 else break;
													 }
												if(!k) break;
											 }
											s.push(num[i++]);
									 }
							 }

								string finalStr = "";

								// 2. If there is some k left, it means num is an increasing sequence 
								// so we delete all elements in the front of num i.e at the top of stack s

								while(k--) 
									s.pop();

								while(s.size()) 
								{
										finalStr = s.top() + finalStr;
										s.pop();
								}

								while(i < num.size()) 
									finalStr += num[i++];

								// To check whether string is not empty
								finalStr = "0" + finalStr ;

								// Delete Leading Zeros
								while(finalStr[0]=='0' && finalStr.size()>1) 
									finalStr.erase(finalStr.begin());
								
								return finalStr;
						}
};