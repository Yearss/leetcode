

#include <vector>

using namespace std;


class Solution {

private:
    int mem[105][105];
    int f(int m, int n, vector<vector<int>>& A){
        if(mem[m][n] != -1)
            return mem[m][n];
        
        if(m == 0)
            return A[m][n];
        
        int mmax = 1e9;
        mmax = min(f(m - 1, n, A), mmax);
        if(n < A[0].size() - 1)
            mmax = min(f(m - 1, n + 1, A), mmax);
        if(n > 0)
            mmax = min(f(m - 1, n - 1, A), mmax);
        
        mem[m][n] = mmax + A[m][n];

        return mem[m][n];

    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        memset(mem, -1, sizeof(mem));
        int M = A.size();
        int ret = -1e9;
        for(int i = 0; i < A[0].size(); i++)
            ret = min(f(M - 1, i, A), ret);

        return ret;
        
    }
};