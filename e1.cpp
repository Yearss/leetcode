
#include <vector>
#include <queue>
#include <iostream>

using namespace std;




bool visited[55][55][55][55];
vector<vector<int>> direct = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


struct Node{
    int px;
    int py;
    int bx;
    int by;
    int step;
    
    Node(int a, int b, int c, int d, int e, Node* f){
        px = a;
        py = b;
        bx = c;
        by = d;
        step = e;
        parent = f;
    }
    Node* parent;
};

bool valid(int x, int y, vector<string>& board){
    int M = board.size(), N = board[0].size();

    if(x < 0 || x >= M || y < 0 || y >= N || board[x][y] == '#')
        return false;
    else
        return true;
}

void bfs(int px, int py, int bx, int by, vector<string>& board, int& ret){


    queue<Node> que;
    que.push(Node(px, py, bx, by, 0, nullptr));
    visited[px][py][bx][by] = true;
    while(!que.empty()){

        auto node = que.front();
        que.pop();
        // cout << "p: " << node.px << " " << node.py << ",b: " << node.bx << " " << node.by << ",s: " << node.step << endl;

        if(board[node.bx][node.by] == 'E'){
            ret = node.step;
            break;
            // 输出路径
            // Node* tmp = &node;
            // while(tmp){
            //     board[tmp->px][tmp->py] = 'x';
            //     board[tmp->bx][tmp->by] = 'y';
            //     cout << tmp->px << ' ' << tmp->py << endl;
            //     cout << tmp->bx << ' ' << tmp->by << endl;
            //     tmp = tmp->parent;
            //     exit(0);
            // }
            // for(int i = 0; i < board.size(); i ++){
            //     for(int j = 0; j < board[0].size(); j++){
            //         cout << board[i][j];
            //     }
            //     cout << endl;
            // }

        }
        else{

            for(int i = 0; i < direct.size(); i++){
                            
                int npx = node.px + direct[i][0];
                int npy = node.py + direct[i][1];

                if(!valid(npx, npy, board))
                    continue;

                int nbx = node.bx, nby = node.by;
                
                if(npx == nbx && npy == nby){
                    nbx += direct[i][0];
                    nby += direct[i][1];
                }

                if(valid(nbx, nby, board) && !visited[npx][npy][nbx][nby]){
                    que.push(Node(npx, npy, nbx, nby, node.step + 1, &node));
                    visited[npx][npy][nbx][nby] = true;
                }
            }
        }
    }

}


int main(){

    int m,  n;
    int bx, by, px, py;
    cin >> m >> n;
    vector<string> board(m);
    for(int i = 0; i < m; i++){
        string t;
        cin >> board[i];
        for(int j = 0; j < n; j++){
            if(board[i][j] == '0'){
                bx = i;
                by = j;
            }
            else if(board[i][j] == 'S'){
                px = i;
                py = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    
    int ret = 1e9;
    bfs(px, py, bx, by, board, ret);

    if(ret == 1e9)
        cout << -1;
    else
        cout << ret ;


}