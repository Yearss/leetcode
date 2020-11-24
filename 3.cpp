

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solve(vector<int>& d, int n){

    sort(d.begin(), d.end());

    int ret = 0, i = 0, cnt = 0, pre;
    while(i < n){
        cnt++;

        if(cnt == 1){
            pre = d[i];
            i++;
        }
        else if(cnt == 3){
            if(d[i] - pre <= 10){
                i++;
            }
            else{
                ret++;
            }
            cnt = 0;
        }
        else{
            if(abs(d[i] - pre) <= 10){
                pre = d[i];
                i++;
            }
            else{
                pre = pre + 10 > d[i] ? d[i] : pre + 10;
                ret++;
            }
        }
    }

    if(cnt == 0)
        return ret;
    else 
        return ret + (3 - cnt);
    

}

int main(){

    int n;
    cin >> n;
    vector<int> d;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        d.push_back(t);
    }

    cout << solve(d, n);
}