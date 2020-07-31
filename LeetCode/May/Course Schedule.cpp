/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5*/

class Solution {
public:
    bool findloop(vector<vector<int>>&adj,int u,vector<int>&visited)
    {
        if(visited[u]==1)
            return 1;
        if(visited[u]==2)
            return 0;
        visited[u] = 1 ;
        for(auto it:adj[u])
        {
            if(findloop(adj,it,visited))
                return 1;
        }
        visited[u] = 2 ;
        return 0;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i  < pre.size() ; i ++)
        {
            for(int j = pre[i].size()-1;j>0;j--)
                adj[pre[i][j]].push_back(pre[i][j-1]);
        }
        vector<int>visited(n,0);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i] && findloop(adj,i,visited))
                return 0;
        }
        return 1 ;
    }
};