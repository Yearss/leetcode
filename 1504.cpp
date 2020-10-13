

#include <vector>

using namespace std;

// TLE
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        
        //计算二维前缀和
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>> prefixSum(M + 1, vector<int>(N + 1, 0));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + mat[i][j];
            }
        }

        // 枚举左上角的点和右下角的点
        int ret = 0;
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                if(mat[i - 1][j - 1] == 0)
                    continue;
                for(int x = i; x<= M; x++){
                    for(int y = j; y <= N; y++){
                        if(mat[x - 1][y - 1] == 0)
                            continue;
                        int area = prefixSum[x][y] - prefixSum[x][j - 1] - prefixSum[i - 1][y] + prefixSum[i - 1][j - 1];
                        int target = (x - i + 1) * (y - j + 1);
                        if(area == target)
                            ret++;
                    }
                }
                
            }
        }
        return ret;
    }
};
