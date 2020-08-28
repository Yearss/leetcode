#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>> ret(M, vector<int>(N, 0));
        vector<int> tmp;
        for(int m = 0; m < M; m++){
            for(int i = m, j = 0; i < M && j < N; i++, j++){
                tmp.push_back(mat[i][j]);
            }
            sort(tmp.begin(), tmp.end(), less<int>());
            for(int i = m, j = 0, k = 0; i < M && j < N; i++, j++, k++){
                ret[i][j] = tmp[k];
            }
            tmp.clear();
        }
        for(int n = 1; n < N; n++){
            for(int i = 0, j = n; i < M && j < N; i++, j++){
                tmp.push_back(mat[i][j]);
            }
            sort(tmp.begin(), tmp.end(), less<int>());
            for(int i = 0, j = n, k = 0; i < M && j < N; i++, j++, k++){
                ret[i][j] = tmp[k];
            }
            tmp.clear();
        }
        return ret;
    }
};