
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
bool visited[25];
void dfs(vector<vector<int>>& pay, int cur, int& ret, int n, int temp, int cnt){

    visited[cur] = true;
    if(cnt == n){
        ret = min(ret, temp + pay[cur][0]);
    }
    else{
        for(int i = 0; i < n; i++){
            if(visited[i])
                continue;
            dfs(pay, i, ret, n, temp + pay[cur][i], cnt + 1);
        }
    }
    visited[cur] = false;
}


int solve(vector<vector<int>>& pay, int n){

    int ret = 1e9;
    dfs(pay, 0, ret, n, 0, 1);

    return ret;

}

int main(){

    memset(visited, false, sizeof(visited));
    int n;
    cin >> n;
    vector<vector<int>> pay;
    for(int i = 0; i < n; i++){
        vector<int> p;
        for(int j = 0; j < n; j++){
            int t;
            cin >> t;
            p.push_back(t);
        }
        pay.push_back(p);
    }

    cout << solve(pay, n);
}