
#include<vector>

using namespace std;



class Solution {
public:
    int minFlips(int a, int b, int c) {

        int A[2][2][2];
        A[0][0][0] = 0;
        A[0][0][1] = 1;
        A[0][1][0] = 1;
        A[0][1][1] = 0;
        A[1][0][0] = 1;
        A[1][0][1] = 0;
        A[1][1][0] = 2;
        A[1][1][1] = 0;

        int t = 0x1, ret = 0;
        for(int i = 0; i < 32; i++){
            int x = a & t;
            int y = b & t;
            int z = c & t;
            ret += A[x][y][z];
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return ret;
    }
};