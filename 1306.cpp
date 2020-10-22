
#include <vector>

using namespace std;


class Solution {
private:
    bool used[50005];
    int dfs(int x, vector<int>& arr){

        if(used[x])
            return false;

        if(x < 0 || x >= arr.size()){
            return 0;
        }
        if(arr[x] == 0)
            return 1;
        
        used[x] = true;
        if(dfs(x + arr[x], arr))
            return 1;
        
        if(dfs(x - arr[x], arr))
            return 1;

        return 0;
        
    }
public:
    bool canReach(vector<int>& arr, int start) {
        memset(used, false, sizeof(used));
        return dfs(start, arr);
    }
};