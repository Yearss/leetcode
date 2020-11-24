
#include <vector>
#include <iostream>


using namespace std;


int solve(int N){

    int left = 1024 - N;
    int ret = 0;
    
    ret += left / 64;
    left = left % 64;
    ret += left / 16;
    left = left % 16;
    ret += left / 4;
    left = left % 4;
    ret += left;

    return ret;
}

int main(){

    int N;
    cin >> N;
    cout << solve(N);
}