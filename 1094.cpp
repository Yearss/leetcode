
#include <vector>
#include <unordered_map>

using namespace std;


bool cmp(vector<int>& a, vector<int>& b){
    
    return a[1] < b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int left = capacity;
        unordered_map<int, int> um;
        sort(trips.begin(), trips.end(), cmp);
        for(int i = 0; i < trips.size(); i++){
            int np = trips[i][0];
            int sl = trips[i][1];
            int dl = trips[i][2];
            
            // 计算目前车上位置
            for(auto iter = um.begin(); iter != um.end(); iter++){
                if(iter->first <= sl){
                    left += iter->second;
                    iter->second = 0;

                }
            }
            // 是否可以上车
            
            if(np <= left){
                left -= np;
                um[dl] = um[dl] + np;
            }
            else
                return false;
            cout << left << endl;
        }

        return true;
        
    }
};