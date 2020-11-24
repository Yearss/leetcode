
#include <iostream>
#include <vector>


using namespace std;

// 从（a,b）到（c,d)
int g(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}

int mem[55][55][55][55];
// 箱子坐标x,y 
// 人坐标m,n
// 人初始位置 sm, sn
int f(int x, int y, int m, int n, vector<string>& board, int sm, int sn){

    int M = board.size(), N = board[0].size();

    cout << x << ' ' << y << ' ' << m << ' ' << n << endl;

    if(x < 0 || x >= M || y < 0 || y >= N || m < 0 || m >= M || n < 0 || n >= N)
        return 1e9;

    if(mem[x][y][m][n] != -1){
        return mem[x][y][m][n];
    }


    // 箱子在初始位置
    if(board[x][y] == '0'){
        return abs(sm - m) + abs(sn - n) ;
    }

    // 箱子在其余位置

    int ret = 1e9;

    //从下到达
    if(x + 1 < M && x + 2 < M && board[x + 1][y] != '#')
        ret = min(f(x + 1, y, x + 2, y, board, sm, sn) + g(m, n, x + 2, y) + 1, ret);
    
    //从上达到
    if(x - 1 >= 0 && x -2 >= 0 && board[x - 1][y] != '#')
        ret = min(f(x - 1, y, x - 2, y, board, sm, sn) + g(m, n, x - 2, y) + 1, ret);
    
    //从左到达
    if(y - 1 >= 0 && y - 2 >=0 && board[x][y - 1] != '#')
        ret = min(f(x, y - 1, x, y - 2, board, sm, sn) + 1 + g(m, n, x, y -2) + 1, ret); 
    
    //从右达到
    if(y + 1 < N && y + 2 < N && board[x][y + 1] != '#')
        ret = min(f(x, y + 1, x, y + 2, board, sm, sn) + 1 + g(m,n, x, y + 2) + 1, ret);

    if(ret == 1e9)
        mem[x][y][m][n] = 1e9;
    else
        mem[x][y][m][n] = ret;

    return ret;

}



int main(){

    int m,  n;
    int sm, sn, tx, ty;
    cin >> m >> n;
    vector<string> board(m);
    for(int i = 0; i < m; i++){
        string t;
        cin >> board[i];
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'E'){
                tx = i;
                ty = j;
            }
            else if(board[i][j] == 'S'){
                sm = i;
                sn = j;
            }
        }
    }

    memset(mem, -1, sizeof(mem));
    
    // int ret = 1e9;
    // ret = min(ret, f(tx, ty, tx - 1, ty, board, sm, sn) + 1);
    // ret = min(ret, f(tx, ty, tx + 1, ty, board, sm, sn) + 1);
    // ret = min(ret, f(tx, ty, tx, ty - 1, board, sm, sn) + 1);
    // ret = min(ret, f(tx, ty, tx, ty + 1, board, sm, sn) + 1);

    // if(ret == 1e9)
    //     cout << -1;
    // else
    //     cout << ret;

    cout << f(0, 3, 0, 2, board, 0 ,0) << endl;
    
}