#define FRESH 1
#define ROTTEN 2

class Solution 
{
        bool rot(vector<vector<int>>& grid, int r, int c) 
        {
            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != FRESH)
                return false;

            grid[r][c] = ROTTEN;

            return true;
        }
    
    public:
            
        int orangesRotting(vector<vector<int>>& grid) 
        {
            queue<pair<int, int>> q;

            int fresh_cnt = 0;
            int time = 0;

            for(int i = 0; i < grid.size(); ++i) 
            {
                for(int j = 0; j < grid.front().size(); ++j) 
                {
                    if(grid[i][j] == FRESH)
                        ++fresh_cnt;

                    if(grid[i][j] == ROTTEN)
                        q.push({i, j});
                }
            }

            if(fresh_cnt == 0)
                return 0;

            if(q.empty())
                return -1;

            while(!q.empty() && fresh_cnt > 0) 
            {
                ++time;
                int n = q.size();

                for(int i = 0; i < n; ++i) 
                {
                    auto [r, c] = q.front(); 
                    q.pop();

                    if(rot(grid, r + 1, c)) 
                    {
                        q.push({r + 1, c});
                        --fresh_cnt;
                    }

                    if(rot(grid, r - 1, c)) 
                    {
                        q.push({r - 1, c});
                        --fresh_cnt;
                    }

                    if(rot(grid, r, c + 1)) 
                    {
                        q.push({r, c + 1});
                        --fresh_cnt;
                    }

                    if(rot(grid, r, c - 1)) 
                    {
                        q.push({r, c - 1});
                        --fresh_cnt;
                    }
                }
            }

            return fresh_cnt == 0 ? time : -1;
        }
};