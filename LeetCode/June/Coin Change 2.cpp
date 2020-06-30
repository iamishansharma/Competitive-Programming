/*

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer

GFG link: https://www.geeksforgeeks.org/coin-change-dp-7/

*/

class Solution 
{
public:
    int count(vector<int> S, int m, int n ) 
    { 
        int i, j, x, y; 
 
        int table[n + 1][m]; 

        for(i = 0; i < m; i++) 
            table[0][i] = 1; 

        for(i = 1; i < n + 1; i++) 
        {
            for (j = 0; j < m; j++) 
            {
                x = (i - S[j] >= 0) ? table[ i - S[j] ][j] : 0;
                y = (j >= 1) ? table[i][j - 1] : 0;
                table[i][j] = x + y;
            } 
        } 
        return table[n][m - 1]; 
    }
    int change(int amount, vector<int>& coins) 
    {
        if(amount == 0)
            return 1;
        else
            if(coins.size() == 0)
                return 0;
        
        return count(coins, coins.size(), amount);
    }
};