
#include <iostream>
#include <vector>


using namespace std;


int parent[100005];
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int m = connections.size();
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int extra = 0;
        for(int i = 0; i < m; i++){
            if(uni(connections[i][0], connections[i][1])){
                extra ++;
            }
        }
        int need = 0;
        for(int i =0; i < n; i++){
            if(parent[i] == i)
                need ++;
        }
        
        if(need - 1 > extra){
            return -1;
        }
        else{
            return need - 1;
        }
    }

    int find(int x){
        while(parent[x] != x)
            x = parent[x];
        return x;
    }

    bool uni(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px == py)
            return true;
        else{
            parent[px] = py;
            return false;
        }
    }
};

int main(){


    vector<vector<int>> vec = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    Solution sol;
    cout << sol.makeConnected(6, vec);
}