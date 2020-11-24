
#include <vector>

using namespace std;


class Solution {
private:
    bool used[20];
    void dfs(int& ret, int x, int N){
        if(x == N + 1){
            ret++;
        }
        else{
            for(int num = 1; num <= N; num++){
                if(used[num])
                    continue;
                if(num % x == 0 || x % num == 0){
                    used[num] = true;
                    dfs(ret, x + 1, N);
                    used[num] = false;
                }
            }
        }
    }
public:
    int countArrangement(int N) {
        int ret = 0;
        dfs(ret, 1, N);
        return ret;
    }
};