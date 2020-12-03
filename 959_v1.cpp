
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:

    int parent[5000];
    int regionsBySlashes(vector<string>& grid) {

        int m = grid.size(), n = grid[0].size();

        // init
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                parent[index(i, j, m, n, 0)] = index(i, j, m, n, 0);
                parent[index(i, j, m, n, 1)] = index(i, j, m, n, 1);
                parent[index(i, j, m, n, 2)] = index(i, j, m, n, 2);
                parent[index(i, j, m, n, 3)] = index(i, j, m, n, 3);
            }
        }

        // 枚举关系
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == '/'){
                    uni(index(i, j, m, n, 1), index(i, j, m, n, 2));
                    uni(index(i, j, m, n, 0), index(i, j, m, n, 3));
                }
                else if(grid[i][j] == '\\'){
                    uni(index(i, j, m, n, 0), index(i, j, m, n, 1));
                    uni(index(i, j, m, n, 2), index(i, j, m, n, 3));
                }
                else{
                    uni(index(i, j, m, n, 0), index(i, j, m, n, 1));
                    uni(index(i, j, m, n, 1), index(i, j, m, n, 2));
                    uni(index(i, j, m, n, 2), index(i, j, m, n, 3)); 
                }

                if(j < n - 1){
                    uni(index(i, j, m, n, 1), index(i, j + 1, m, n, 3));
                }
                
                if(i < m - 1){
                    uni(index(i, j, m, n, 2), index(i + 1, j, m, n, 0));
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < m * n * 4; i++){
            if(parent[i] == i)
                ret++;
        }

        return ret;

    }

    int find(int x){
        while(parent[x] != x){
            x = parent[x];
        }
        return x;
    }

    void uni(int x, int y){

        int px = find(x);
        int py = find(y);

        parent[px] = py;

    }

    int index(int x, int y, int m, int n, int offset){
        return x * n * 4 + 4 * y + offset;
    }

};

int main(){

    Solution sol;
    vector<string> vec = {"/\\","\\/"};
    cout << sol.regionsBySlashes(vec) << endl;

}