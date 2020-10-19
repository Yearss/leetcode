

#include <vector>

using namespace std;

class Solution {
private:
    bool used[50005];
    void dfs(int& ret, int x, int n, vector<vector<int>>& edge){
        used[x] = true;
        for(int i = 0; i < n; i++){
            if(used[i])
                continue;
            if(edge[x][i] == 1){
                ret++;
                dfs(ret, i, n, edge);
            }
            else if(edge[i][x] == 1){
                dfs(ret, i, n, edge);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        memset(used, false, sizeof(used));
        vector<vector<int>> edge(n, vector<int>(n ,0));
        for(int i = 0; i < connections.size(); i++){
            edge[connections[i][0]][connections[i][1]] = 1;
        }

        int ret = 0;
        dfs(ret, 0, n, edge);

        return ret;
    }
};