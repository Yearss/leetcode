

#include <vector>


using namespace std;

class Solution {

void dfs(int x, int y, int m, int n, vector<vector<int>>& A){

    if(x < m && x >= 0 && y >= 0 && y < n && A[x][y] == 1){
        A[x][y] = 0;
        dfs(x + 1, y, m, n, A);
        dfs(x - 1, y, m, n, A);
        dfs(x, y + 1, m, n, A);
        dfs(x, y - 1, m, n, A);
    }
}
public:
    int numEnclaves(vector<vector<int>>& A) {
        int ret = 0;
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++){
            dfs(i, 0, m, n, A);
            dfs(i, n - 1, m, n, A);
        }
        for(int i = 0; i < n; i++){
            dfs(0, i, m, n, A);
            dfs(m - 1, i, m, n, A);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                if(A[i][j] == 1)
                    ret++;
        }

        return ret;

    }
};