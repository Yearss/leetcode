
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// TLE
class Solution {
private:
    bool dfs(vector<int>& ret, int k, vector<bool>& used, unordered_map<int, int>& um, int N){
        if(k == N + 1)
            return true;

        for(int x = 1; x <= N; x++){
            if(used[x] || um.count(x))
                continue;

            // 在第k位置选择x
            used[x] = true;
            ret[k] = x;
            for(int i = 1; i < k; i++){
                um[ret[k] * 2 - ret[i]] = um[ret[k] * 2 - ret[i]] + 1;
            }
            
            if(dfs(ret, k + 1, used, um, N))
                return true;

            // 恢复
            used[x] = false;
            for(int i = 1; i < k; i++){
                um[ret[k] * 2 - ret[i]] = um[ret[k] * 2 - ret[i]] - 1;
                if(um[ret[k] * 2 - ret[i]] == 0)
                    um.erase(ret[k] * 2 - ret[i]);
            }
        }

        return false;

    }
public:
    vector<int> beautifulArray(int N) {
        
        vector<bool> used(N + 1, false);
        vector<int> ret(N + 1, 0);
        unordered_map<int, int> um;
        dfs(ret, 1, used, um, N);

        return vector<int>(ret.begin()+1, ret.end());

    }
};