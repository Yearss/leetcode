#include <vector>

using namespace std;


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        
        int M = A.size(), N = A[0].size();
        // 第一列全为1
        for(int i = 0; i < M; i ++){
            if(A[i][0] == 0){
                for(int j = 0; j < N; j++)
                    A[i][j] = 1 - A[i][j];
            }
        }

        // 枚举每一列
        for(int j = 1; j < N; j++){
            int s = 0;
            for(int i = 0; i < M; i++){
                s += A[i][j];
            }
            if(M - s > s){
                for(int i = 0; i < M; i++)
                    A[i][j] = 1 - A[i][j];
            }
        }

        // 求和
        int ret = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++)
                if(A[i][j] != 0)
                    ret += (1 << (N - 1 - j));
        }

        return ret;


    }
};