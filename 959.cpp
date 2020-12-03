#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    void dfs(int x, int y, int m, int n, vector<vector<int>>& grid){
        
        if(x >= 0 && x < m && y >=0 && y < n && grid[x][y] == 0){
            grid[x][y] = 1;
            dfs(x, y - 1, m, n, grid);
            dfs(x, y + 1, m, n, grid);
            dfs(x + 1, y, m, n, grid);
            dfs(x - 1, y, m, n, grid);
        }
      
    }

    int regionsBySlashes(vector<string>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> extendGrid(m * 3, vector<int>(n * 3));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    extendGrid[3 * i][3 * j + 2] = 1;
                    extendGrid[3 * i + 1][3 * j + 1] = 1;
                    extendGrid[3 * i + 2][3 * j] = 1;
                }
                else if (grid[i][j] == '\\'){
                    extendGrid[3 * i][3 * j] = 1;
                    extendGrid[3 * i + 1][3 * j + 1] = 1;
                    extendGrid[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < 3 * m; i++){
            for(int j = 0; j < 3 * n; j++){
                if(extendGrid[i][j] == 0){
                    dfs(i, j, m * 3, n * 3, extendGrid);
                    ret++;
                }
            }
        }

        return ret;
    }
};

int main(){

    Solution sol;
    vector<string> vec = {"//","/ "};
    cout << sol.regionsBySlashes(vec) << endl;

}