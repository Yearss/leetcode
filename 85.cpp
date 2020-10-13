
#include <vector>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
      
        int M = mat.size(), N = mat[0].size();

        // 预处理向左延伸最大长度
        vector<vector<int>> l(M, vector<int>(N, 0));
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 0){
                    l[i][j] = 0;
                }
                else{
                    l[i][j] = j > 0 ? l[i][j - 1] + 1 : 1;
                }
            }
        }

        // 枚举每一个右下角的点
        int ret = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 0)
                    continue;
                
                for(int k = i, mmin = 1e9; k >= 0; k--){
                    mmin = min(mmin, l[k][j]);
                    ret += mmin;
                }
            }
        }
        return ret;

    }
};
