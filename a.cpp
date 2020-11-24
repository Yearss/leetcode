

#include <iostream>

using namespace std;

int mem[1001][2];
int f(int x, int y, vector<int>& p){

    if(mem[x][y] != -1)
        return mem[x][y];
    
    if(x == 1 && y == 1)
        return 0;
    
    int ret = 0;
    
    // 

}

int main(){

    int n;
    cin >> n;

    int p[1001];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    int ret = 0, des = 1;
    int MOD = 1e9+7;
    int cnt[1001];
    memset(cnt, 0, sizeof(cnt));
    while(des != n + 1){

        cnt[des] ++;
        if(cnt[des] % 2 == 0)
            des = des + 1;
        else
            des = p[des - 1];
        
        ret = (ret + 1) % MOD;
    }

    cout << ret;

}

