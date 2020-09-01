
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        int M = mat.size(), N = mat[0].size(); 

        // 计算二维前缀和
        vector<vector<int>> prefixSum(M + 1, vector<int>(N + 1));
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                prefixSum[i][j] = prefixSum[i][j-1] + mat[i-1][j-1]; 
            }
        }
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j];
            }
        }

        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                int r = i - K > 0 ? i - K : 1;
                int c = j - K > 0 ? j - K : 1;

                int r1 = i + K <= M ? i + K: M;
                int c1 = j + K <= N ? j + K: N;

                mat[i-1][j-1] = prefixSum[r1][c1] - prefixSum[r1][c-1] - prefixSum[r-1][c1] + prefixSum[r-1][c-1];
            }
        }

        return mat;

    }
};