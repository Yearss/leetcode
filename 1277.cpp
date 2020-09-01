#include<vector>

using namespace std;


class Solution {

private:
    bool checkValid(vector<vector<int>>& matrix, int r, int c, int side){
        for(int i = 0; i < side; i++){
            for(int j = 0; j < side; j++){
                if(matrix[r+i][c+j] == 0)
                    return false;
            }
        }

        return true;
    }    
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int M = matrix.size(), N = matrix[0].size();
        int ret = 0;
        for(int i = 0; i < M ; i++){
            for(int j = 0; j < N; j++){
                for(int side = 1; side <= min(M - i, N - j); side++){
                    if(checkValid(matrix, i, j, side))
                        ret++;
                    else
                        break;
                }
            }
        }

        return ret;

    }
};