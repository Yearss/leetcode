
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solve(unordered_map<int, vector<int>>& um, int m, int c, int N){

    int ret = 0;
    for(int k = 1; k <= c; k++){
        auto vec = um[k];
        int n = vec.size(), minDis = 1e9;
        for(int i = 0; i < n; i ++){
            // cout << "ind: " << vec[i] << endl;
            int next = (i + 1) % n;
            if(vec[next] >= vec[i])
                minDis = min(minDis, vec[next] - vec[i] + 1);
            else
                minDis = min(minDis, N - vec[i] + 1 + vec[next]);
        }
        // cout << minDis << endl;
        if(minDis <= m && minDis > 1){
            // cout << k << endl;
            ret++;
        }

    }
    return ret;
}

int main(){


    int n, m, c;
    cin >> n >> m >> c;
    unordered_map<int, vector<int>> um;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int t;
            cin >> t;
            um[t].push_back(i);
        }
    }

    cout << solve(um, m, c, n);
    

}