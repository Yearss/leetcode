
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size();
        int ret = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]){
                ret += min(cost[i], cost[i - 1]);
                cost[i] = max(cost[i], cost[i - 1]);
            }
        }

        return ret;
    }
};