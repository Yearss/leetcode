
#include <vector>

using namespace std;

class Solution {
private:
    int mem[600][600];
    int f(int i , int j, vector<int>& piles){
        if(j - i == 1)
            return abs(piles[i] - piles[j]);
        
        if(mem[i][j] != -1)
            return mem[i][j];
        
        int mmax = -1e9;

        mmax = max(mmax, min(f(i+1, j-1, piles) + piles[i] - piles[j], f(i+2, j, piles) + piles[i] - piles[i+1]));
        mmax = max(mmax, min(f(i+1, j-1, piles) + piles[j] - piles[i], f(i, j-2, piles) + piles[j] - piles[j-1]));

        mem[i][j] = mmax;

        return mem[i][j];
    }
public:
    bool stoneGame(vector<int>& piles) {

        memset(mem, -1, sizeof(mem));

        int N = piles.size();

        return f(0, N-1, piles) > 0;

    
    }
};