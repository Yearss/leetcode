

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// TLE
class Solution {

private:
    bool used[100000];
    bool dfs(int x, int& n, vector<int>& ret){

        if(x == int(pow(2, n))){
            int m = ret[x - 1] ^ ret[0];
            if(m & (m - 1) == 0)
                return true;
            else
                return false;
        }
    
        for(int i = 0; i < n; i++){
            int tmp = 1 << i;
            int m = ret[x-1] ^ tmp;
            if(used[m])
                continue;
            used[m] = true;
            ret.push_back(m);
            if(dfs(x + 1, n, ret))
                return true;
            used[m] = false;
            ret.pop_back();
        }
        
        return false;

    }
public:
    vector<int> circularPermutation(int n, int start) {

        memset(used, false, sizeof(used));
        vector<int> ret;
        ret.push_back(start);
        used[start] = true;
        dfs(1, n, ret);

        return ret;

    }
};


// O(n)

class Solution {

public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> ret;
       
        // 格雷码转原码
        for(int i = n - 1; i > 0; i--){
            int t = 1 << i;
            int u = start & t;
            start = start ^ (u >> 1);
        }

        for(int i = 0; i < i << n; i++){
            int x = (i + start) % (i << n);
            int y = x >> 1;
            ret.push_back(x ^ y);   
        }

        return ret;
    }
};

int main(){
    Solution solu;

    auto x = solu.circularPermutation(3, 2);
    cout << x << endl;
}



