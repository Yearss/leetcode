
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


int parent[300];

// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
        
//         int m = grid.size(), n = grid[0].size();

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 parent[g(i,j,m,n)] = g(i,j,m,n);
//             }
//         }

//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if()
//                 if(j < n - 1){
//                     uni(g(i, j, m, n), g(i, j + 1, m, n));
//                 }
//                 if(i < m - 1){
//                     uni(g(i, j, m, n), g(i + 1, j, m, n));
//                 }
//             }
//         }

//         int ret = -1;
//         unordered_map<int, int> um;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 int x = g(i, j, m, n);
//                 um[find(x)] = um[find(x)] + 1;
//                 ret = max(um[find(x)], ret);
//             }
//         }

//         return ret;

//     }

//     void uni(int x, int y){
//         int px = find(x);
//         int py = find(y);
        
//         if(px != py){
//             parent[px] = py;
//         }
//     }

//     int find(int x){
//         while(parent[x] != x){
//             x = parent[x];
//         }
//         return x;
//     }

//     int g(int x, int y, int m, int n){
//         return x * m + y;
//     }
// };

class Solution {

public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<int> colNum, rowNum;
        for(int i = 0; i < m; i++){
            int t = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    t++;
            }
            rowNum.push_back(t);
        }
        for(int i = 0; i < n; i++){
            int t = 0;
            for(int j = 0; j < m; j++){
                if(grid[j][i] == 1)
                    t++;
            }
            colNum.push_back(t);
        }

        int ret = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && (colNum[j] > 1 || rowNum[i] > 1))
                    ret++;
            }
        }
        return ret;
    }
};


int main(){

    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};

    Solution sol;
    cout << sol.countServers(grid);
}