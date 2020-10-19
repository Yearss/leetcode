
#include <vector>

using namespace std;

class Solution {
private:
    bool visited[105][105];
    bool dfs(vector<vector<int>>& grid, int x, int y){
        int M = grid.size(), N = grid[0].size();
        if(x == M || y == N || x == -1 || y == -1)
            return false;
        if(grid[x][y] == 1 || visited[x][y])
            return true;
        
        bool ret = true;
        visited[x][y] = true;
        ret =  dfs(grid, x+1, y) && ret;
        ret = dfs(grid, x-1,y) && ret;
        ret = dfs(grid, x, y-1) && ret;
        ret = dfs(grid, x, y+1) && ret;
    
        return ret;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int M = grid.size(), N = grid[0].size(), ret = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1 || visited[i][j])
                    continue;
                if(dfs(grid, i, j))
                    ret++;
            }
        }
        return ret;
    }
};