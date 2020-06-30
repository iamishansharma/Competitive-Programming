/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28*/

class Solution 
{
    public:
            /*void dfs(int i, int j, int m, int n, int &paths)
            {
                if(i == m || j == n)
                    return;
                
                if(i == m-1 && j == n-1)
                {
                    paths++;
                    return;
                }
                
                dfs(i+1, j, m, n, paths);
                dfs(i, j+1, m, n, paths);
            }
    
            int uniquePaths(int m, int n) 
            {
                if(m == 1 || n == 1)
                    return 1;
                
                int paths = 0;
                dfs(0, 0, m, n, paths);
                return paths;
            }*/
            int uniquePaths(int m, int n) 
            {
                if(m == 1 || n == 1)
                    return 1;

                int dp[m][n];
                
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        dp[i][j] = (i==0 && j==0) ? 1 : 0;
                        
                        if(i > 0)
                            dp[i][j] += dp[i-1][j];
                        
                        if(j > 0)
                            dp[i][j] += dp[i][j-1];
                    }
                }
                return dp[m-1][n-1];
            }
};