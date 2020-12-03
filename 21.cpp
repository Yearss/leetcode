

#include <iostream>
#include <vector>

using namespace std;

string solve(long n, long k, long d1, long d2){

    if(n % 3 != 0)
        return "no";

    
    long alpha = n / 3;

    long a = (k - d1 - d2) / 3;
    cout << "a: " << a << endl;
    cout << "a+d1: " << a + d1 << endl;
    cout << "a + d2: " << a + d2 << endl;
    if(a >= 0 && max(a + d1, a + d2) <= alpha)
        return "yes";

    a = (k - d2 + d1) / 3;
    cout << "a: " << a << endl;
    if(a >= d1 && a + d2 <= alpha)
        return "yes";
    
    a = (k + d1 + d2)  / 3;
    cout << "a: " << a << endl;
    if(min(a - d1, a - d2) >= 0 && a <= alpha)
        return "yes";

    a = (k - d1 + d2) / 3;
    cout << "a: " << a << endl;
    if(a >= d2 && a + d1 <= alpha)
        return "yes";
    
    return "no";
}


int main(){


    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        
        long n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        cout << solve(n, k, d1, d2) << endl;
    }

}