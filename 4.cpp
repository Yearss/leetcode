
#include <vector>
#include <iostream>

using namespace std;


bool check(vector<int>& h, int m){

    long e = m;
    for(int i = 0; i < h.size(); i++){
        e = e * 2 - h[i];
        if(e < 0)
            return false;
        if(e > 1e5)
            return true;
    }
    return true;

}

int solve(vector<int>& h, int n){

    int s = 1, e = 1e5 + 1;
    
    while(s < e){

        int m = (s + e) / 2;
        if(check(h, m)){
            e = m;
        }
        else{
            s = m + 1;
        }
    }

    return s;
}


int main(){


    int n;
    cin >> n;
    vector<int> h;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        h.push_back(t);
    } 

    cout << solve(h, n);
}