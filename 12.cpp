

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double solve(int n, int m){
    
    double ret = 0, x = n;
    for(int i = 0; i < m; i++){
        ret += x;
        x = pow(x, 1.0 / 2);
    } 

    return ret;
}

int main(){


    int n, m;
    while(cin >> n >> m){
        cout.setf(ios::fixed);
        cout<<setprecision(2) << solve(n, m) << endl;
    }
}