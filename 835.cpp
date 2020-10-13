
#include <vector>

using namespace std;

class Solution {

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int M = img1.size(), N = img1[0].size();
        int ret = -1;
        for(int i = 1 - M; i < M; i++){
            for(int j = 1 - N; j < N; j++){
                
                // 计算overlap
                int overlap = 0;
                for(int x = 0; x < M; x++){
                    for(int y = 0; y < N; y++){
                        if(img2[x][y] == 0)
                            continue;
                        int ni = i + x;
                        int nj = j + y;
                        if(ni < M && ni >= 0 && nj >= 0 && nj < N && img1[ni][nj] == img2[x][y]){
                            overlap ++;
                        }
                    }
                }
                ret = max(ret, overlap);

            }
        }

        return ret;

    }
};