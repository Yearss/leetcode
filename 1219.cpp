
#include <vector>

using namespace std;

class Solution {

private:
    bool used[20][20];
    void dfs(int i, int j, int& M, int& N, vector<vector<int>>& grid, int curGlod, int& ret){
        used[i][j] = true;
        curGlod += grid[i][j];

        // UP
        bool ctn = false;
        if(i-1 >= 0 && grid[i-1][j] > 0 && !used[i-1][j]){
            ctn = true;
            dfs(i - 1, j, M, N, grid, curGlod, ret);
        }
        
        // DOWN
        if(i + 1 < M && grid[i+1][j] > 0 && !used[i+1][j]){
            ctn = true;
            dfs(i + 1, j, M, N, grid, curGlod, ret);
        }

        // LEFT
        if(j - 1 >= 0 && grid[i][j-1] > 0 && !used[i][j-1]){
            ctn = true;
            dfs(i, j - 1, M, N, grid, curGlod, ret);
        }

        // RIGHT
        if(j + 1 < N && grid[i][j+1] > 0 && !used[i][j+1]){
            ctn = true;
            dfs(i, j + 1, M, N, grid, curGlod, ret);
        }

        if(!ctn && curGlod > ret){
            ret = curGlod;
        }

        used[i][j] = false;
        
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int curGlod = 0, M = grid.size(), N = grid[0].size();
        int ret = -1;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                memset(used, false, sizeof(used));
                dfs(i, j, M, N, grid, curGlod, ret);
            }
        }
        
        return ret;

    }
};