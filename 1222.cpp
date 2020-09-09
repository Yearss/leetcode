
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> ret;
        int N = queens.size(), maxR = -1;
        vector<vector<bool>> exist(9, vector<bool>(9,false));
        for(int i = 0; i < N; i++){
            exist[queens[i][0]][queens[i][1]] = true;
            int mR = max(abs(queens[i][0] - king[0]), abs(queens[i][1] - king[1]));
            maxR = max(maxR, mR);
        }
        
        vector<pair<int,int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1,-1},{1, -1}};
        
        for(int i = 0; i < direct.size(); i++){
            for(int r = 1; r <= maxR; r++){
                int x = king[0] + r * direct[i].first;
                int y = king[1] + r * direct[i].second;
                if(x > 8 || y > 8 || x < 0 || y < 0)
                    continue;
                if(exist[x][y]){
                    ret.push_back({x,y});
                    break;
                }
            }
        }

        return ret;        
    }
};



