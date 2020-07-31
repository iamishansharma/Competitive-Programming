/*Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].*/

#define WHITE 0
#define RED 1
#define BLUE 2

class Solution 
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &edges) 
    {
        vector<vector<int>> adj(N + 1); // adjacency list for undirected graph
        vector<int> color(N + 1, WHITE); // color of each vertex in graph, initially WHITE
        vector<bool> explored(N + 1, false); // to check if each vertex has been explored exactly once
        
        // create adjacency list from given edges
        for (auto &edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // print adjacency list (comment out before submitting)
        for (int i = 0; i <= N; ++i)
        {
            cout << "adj[" << i << "]: ";
            for (int j = 0; j < adj[i].size(); ++j)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        
        // queue to perform BFS over each connected component in the graph
        // while performing BFS, we check if we encounter any conflicts while
        // coloring the vertices of the graph
        // conflicts indicate that bi-partition is not possible
        queue<int> q;
        
        for (int i = 1; i <= N; ++i)
        {
            if (!explored[i])
            {
                // this component has not been colored yet
				// we color the first vertex RED and push it into the queue
                color[i] = RED;
                q.push(i);
                
                // perform BFS from vertex i
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    
                    // check if u is already explored 
                    if (explored[u])
                    {
                        continue;
                    }
                    
                    explored[u] = true;
                    
                    // for each neighbor of u, execute this loop
                    for (auto v: adj[u])
                    {
                        // v is u's neighboring vertex
                        
                        // checking if there's any conflict in coloring
                        if (color[v] == color[u])
                        {
							// conflict edge found, so we return false 
							// as bi-partition will not be possible
                            return false;
                        }
                        
                        // we color v with the opposite color of u
                        if (color[u] == RED)
                        {
                            color[v] = BLUE;
                        }
                        else 
                        {
                            color[v] = RED;
                        }
                        
                        q.push(v);
                    }
                }
            }
        }
        
        // if no conflicts encountered then graph must be bipartite
        // so we return true
        
        return true;
    }
};