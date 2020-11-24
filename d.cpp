
#include <vector>
#include <iostream>


using namespace std;


// 预定义索引
vector<vector<int>> A = {{0,2,6,12,16,18,20,22}, {1,3,7,13,17,19,21,23},{4,5,6,7,8,9,22,23}
    ,{10,11,12,13,14,15,20,21}, {5,11,16,17,14,8,3,2},{4,10,18,19,15,9,1,0}};
vector<vector<int>> B = {{4,5,11,10},{9,8,14,15},{0,2,3,1},{18,16,17,19},{6,12,13,7},{22,20,21,23}};

int computeRet(vector<int>& vec){
    int ret = 0;
    for(int i = 0; i < 6; i++){
        int s = 1;
        for(int j = 0; j < 4; j++)
            s = vec[B[i][j]] * s;
        ret += s;
    }
    return ret;
}

void rotate(vector<int>& x, vector<int>& y, int clockWise, vector<int>& vec){
    
    // 轮换
    vector<int> tmp(vec);
    for(int i = 0; i < 8; i++){
        int np;
        if(clockWise == 0)
            np = (i + 2) % 8;
        else
            np = (i + 6) % 8;
        tmp[x[np]] = vec[x[i]];
    }

    // 轮换
    for(int i = 0; i < 4; i++){
        int np;
        if(clockWise == 0)
            np = (i + 1) % 4;
        else 
            np = (i + 3) % 4;
        tmp[y[np]] = vec[y[i]];
    }

    for(int i = 0; i < vec.size(); i++){
        vec[i] = tmp[i];
    }


}

void print(vector<int>& vec){
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' ';
    cout << endl;
}



void f(int& ret, int x, vector<int>& vec, int m, int preOp, int preClockWise){
    
    int t = computeRet(vec);
    ret = max(t, ret);

    if(x == m){
       return ;
    }
    else{

        // 枚举每一面的旋转
        for(int i = 0; i < 6; i++){

            if(preOp == i && preClockWise == 1){
                rotate(A[i], B[i], 1, vec);
                f(ret, x + 1, vec, m, i, 1);
                rotate(A[i], B[i], 0, vec);
            }
            else if(preOp == i && preClockWise == 0){
                rotate(A[i], B[i], 0, vec);
                f(ret, x + 1, vec, m, i, 0);
                rotate(A[i], B[i], 1, vec);
            }
            else{
                rotate(A[i], B[i], 0, vec);
                f(ret, x + 1, vec, m, i, 0);
                rotate(A[i], B[i], 1, vec);

                rotate(A[i], B[i], 1, vec);
                f(ret, x + 1, vec, m, i, 1);
                rotate(A[i], B[i], 0, vec); 
            }
        }
    }

}


int main(){

    vector<int> vec(24);

    for(int i = 0; i < 24; i++)
        cin >> vec[i];

    int ret = -1e9;
    f(ret, 0, vec, 4, -1, -1);

    cout << ret;


    

}
