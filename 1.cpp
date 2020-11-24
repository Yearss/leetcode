

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


long countNode(long x, long n){

   long ret = 0, base = 1, start = x;
   while(start <= n){
       
        long  end = (x + 1) * base - 1;
        if(end <= n)
            ret += end - start + 1;
        else{
            ret += n - start + 1;
        }
        base *= 10;
        start = x * base;
   }

   return ret;

}

long solve(long m, long n){

    long  cur = 1;
    while(m > 1){
        long  nc = countNode(cur, n);
        // cout << "cur: " << cur << endl;
        // cout << "nc: " << nc << endl;
        if(nc >= m){
            cur = 10 * cur;
            m--;
        }
        else{
            cur = cur + 1;
            m = m - nc;
        }
    }

    return cur;

   
}


int main(){

    long  m, n;
    cin >> n >> m;
    cout << solve(m, n);

}