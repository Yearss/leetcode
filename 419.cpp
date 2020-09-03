#include <vector>

using namespace std;

class Solution {

public:
    int countBattleships(vector<vector<char>>& board) {

        int M = board.size(), N = board[0].size();
        int ret = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 'X')
                    ret ++;
                if(board[i][j] == '.')
                    continue;
                if(i - 1 >= 0 && board[i-1][j] == 'X')
                    ret --;
                if(j - 1 >=0 && board[i][j-1] == 'X')
                    ret --;
            }
        }
        
        return ret;
    }
};