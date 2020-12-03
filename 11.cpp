

#include <iostream>
#include <vector>

using namespace std;

bool check(int x){

    int s = 0, t = x;
    while(t > 0){
        s += (t % 10) * (t % 10) * (t % 10);
        t = t / 10;
    }

    return s == x;

}

vector<int> solve(int m, int n){

    vector<int> ret; 
    for(int x = m; x <= n; x++){
        if(check(x))
            ret.push_back(x);
    }
    return ret;
    
}
int main(){

    int m, n;

    while (cin >> m >> n)
    {
        auto ret = solve(m, n);
        if(ret.empty())
            cout << "no" << endl;
        else{
            for(int i = 0; i < ret.size(); i++)
                cout << ret[i] << ' ';
            cout << endl;
        }
    
    }
    
}