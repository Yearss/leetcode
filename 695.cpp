

#include <vector>
#include <queue>

using namespace std;


class Solution {
private:

    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){


        if(grid[x][y] == 0)
            return 0;
        else{
            int ret = 1;
            visited[x][y] = true;
            int M = grid.size(), N = grid[0].size();
            if(x + 1 < M && !visited[x + 1][y])
                ret += dfs(grid, x + 1, y, visited);
            if(x - 1 >= 0 && !visited[x - 1][y])
                ret += dfs(grid, x - 1, y, visited);
            if(y + 1 < N && !visited[x][y + 1])
                ret += dfs(grid, x, y + 1, visited);
            if(y - 1 >= 0 && !visited[x][y - 1])
                ret += dfs(grid, x, y - 1, visited);
            return ret;
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int M = grid.size(), N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int ret = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                int t = dfs(grid, i, j, visited);
                if(t > ret)
                    ret = t;
            }
        }
        return ret;
    }
};