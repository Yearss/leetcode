
#include <vector>
#include <map>


using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        map<int, vector<pair<int,int>>> m;
        int N = points.size();
        for(int i = 0; i < N; i++){
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            m[dis].push_back({points[i][0], points[i][1]});
        }

        vector<vector<int>> ret;
        int cnt = 0;
        for(auto iter = m.begin(); iter != m.end(); iter++){
            for(int i = 0; i < iter->second.size(); i++){
                if(cnt < K){
                    ret.push_back({iter->second[i].first, iter->second[i].second});
                    cnt++;
                }
            }        
        }

        return ret;
        

    }
};