
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// int cnt = 0;
// bool visited[25];
// void dfs(vector<vector<int>>& pay, int cur, int& ret, int n, int temp, int cnt){

//     visited[cur] = true;
//     if(cnt == n){
//         ret = min(ret, temp + pay[cur][0]);
//     }
//     else{
//         for(int i = 0; i < n; i++){
//             if(visited[i])
//                 continue;
//             dfs(pay, i, ret, n, temp + pay[cur][i], cnt + 1);
//         }
//     }
//     visited[cur] = false;
// }


struct PairHash{

    template<class T1, class T2> 
    size_t operator() (const pair<T1, T2>& p) const{
        auto h1 = hash<T1>()(p.first);
        auto h2 = hash<T2>()(p.second);

        return h1 ^ h2;
    }
};

// unordered_map<pair<int, int>, int, PairHash> um;
int um[20][1<<19];
int f(vector<vector<int>>& pay, int start, int vset){

    // cout << "start: " << start << endl;
    // cout << "vset: " << vset << endl;
    if(vset == 0)
        return pay[start][0];

    if(um[start][vset] != -1)
        return um[start][vset];
        // return um[{start, vset}];

    int ret = 1e9;
    for(int i = 0; i < 21; i++){
        int x = (vset >> i) & 0x01;
        if(x > 0){
            int new_vset = vset ^ (0x01 << i);
            ret = min(ret, f(pay, i, new_vset) + pay[start][i]);
        }
    }

    um[start][vset] = ret;

    return ret;

}

int solve(vector<vector<int>>& pay, int n){

    int vset = 0;
    memset(um, -1, sizeof(um));
    for(int i = 1; i < n; i++){
        vset = vset | (0x01 << i);
    }

    return f(pay, 0, vset);

}

int main(){

    // memset(visited, false, sizeof(visited));
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