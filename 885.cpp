#include <vector>
#include <queue>
#include <utility>

using namespace std;


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {

        vector<vector<int>> ret;
        pair<int,int> center = {r0, c0}, start = {r0, c0};
        ret.push_back({center.first, center.second});

        for(int i = 1; i < max(R, C); i++){
            start = {start.first, start.second + 1};

            //向下
            int x;
            for(x = start.first; x <= center.first + i; x++)
                if(x < R && x >=0  && start.second >=0 && start.second < C)
                    ret.push_back({x, start.second});
            start.first = x - 1;        
            //向左
            for(x = start.second - 1; x >= center.second - i; x--)
                if(x >= 0 && x < C && start.first >=0 && start.first < R)
                    ret.push_back({start.first, x});
            start.second = x + 1;
            //向上
            for(x = start.first - 1; x >= center.first - i; x--)
                if(x >= 0 && x < R &&  start.second >= 0 && start.second < C)
                    ret.push_back({x, start.second});
            start.first = x + 1;
            for(x = start.second + 1; x <= center.second + i; x++)
                if(x < C && x >= 0 && start.first >=0 && start.first < R)
                    ret.push_back({start.first, x});
            start.second = x - 1;

        }
        
        return ret;

    }
};