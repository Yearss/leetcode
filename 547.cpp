

#include <vector>
#include <iostream>

using namespace std;

int parent[250];
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        int n = M.size();
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(M[i][j] == 1){
                    uni(i, j);
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++)
            if(parent[i] == i)
                ret++;

        return ret;
    }

    int find(int x){
        while(parent[x] != x)
            x = parent[x];

        return x;
    }

    void uni(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px != py)
            parent[px] = py;
    }
};

int main(){

    vector<vector<int>> v = {{1,1,0},{1,1,0},{0,0,1}};
    Solution sol;
    cout << sol.findCircleNum(v);
}