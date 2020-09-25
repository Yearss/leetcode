
#include <vector>
#include <iostream>

using namespace std;

// 想复杂了，没认真读题, 想成了比较难的一种情况, 实际这个题目很简单
// class Solution {

// private:
//     int mem[110][110][110];
//     int f(int i, int j, int m, vector<int>& prefixSum){

//         cout << "i: " << i << ",j: " << j << ",m: " << m << endl;
    
//         if(mem[i][j][m] != -1)
//             return mem[i][j][m];

//         if(j - i + 1 <= m)
//             return prefixSum[j] - prefixSum[i - 1];
        
//         int ret = -1;
//         for(int x = 1; x <= min(2 * m, j - i + 1); x++){
//             for(int u = 0; u <= x; u++){
//                 int w = x - u;
//                 int s = prefixSum[i+u-1] - prefixSum[i-1] + prefixSum[j] - prefixSum[j-w];
//                 int o = f(i + u, j - w, max(x, m), prefixSum);

//                 ret = max(s + prefixSum[j] - prefixSum[i - 1] - o, ret);
//             }
//         }

//         mem[i][j][m] = ret;

//         return ret;

//     }

// public:
//     int stoneGameII(vector<int>& piles) {
    
//         memset(mem, -1, sizeof(mem));
//         vector<int> prefixSum = {0};
//         int s = 0;
//         for(int i = 0; i < piles.size(); i++){
//             s += piles[i];
//             prefixSum.push_back(s);
//         }

//         return f(1, piles.size(), 1, prefixSum);
//     }
// };

// 认真读题
class Solution {

private:
    int mem[110][110];
    int f(int i, int& n, int m, vector<int>& prefixSum){

        if(mem[i][m] != -1)
            return mem[i][m];

        if(n - i + 1 <= m)
            return prefixSum[n] - prefixSum[i - 1];
        
        int ret = -1;
        for(int x = 1; x <= min(2 * m, n - i + 1); x++){
            
            int o = f(i + x, n, max(m, x), prefixSum);
            int s = prefixSum[i+x-1] - prefixSum[i-1];

            ret = max(s + prefixSum[n] - prefixSum[i + x - 1] - o, ret);
            
        }

        mem[i][m] = ret;
        return ret;

    }

public:
    int stoneGameII(vector<int>& piles) {
    
        memset(mem, -1, sizeof(mem));
        vector<int> prefixSum = {0};
        int s = 0, N = piles.size();
        for(int i = 0; i < N; i++){
            s += piles[i];
            prefixSum.push_back(s);
        }

        return f(1, N, 1, prefixSum);
    }
};

int main(){

    vector<int> piles = {2,7,9,4,4};
    Solution solu;
    cout << solu.stoneGameII(piles) << endl;

    return 0;
}