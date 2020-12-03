
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 第一个大于target的下标
int solve1(vector<int>& vec, int target){

    int n = vec.size();
    int s = 0, e = n - 1;
    while(s < e){

        int m = (s + e) / 2;
        if(vec[m] <= target){
            s = m + 1;
        }
        else{
            e = m;
        }
    }

    if(vec[s] > target)
        return s;
    else 
        return n;

}

// 第一个大于等于target的下标
int solve2(vector<int>& vec, int target){

    int n = vec.size();
    int s = 0, e = n - 1;

    while(s < e){
        int m = (s + e) / 2;
        if(vec[m] >= target){
            e = m;
        }
        else{
            s = m + 1;
        }
    }

    if(vec[s] >= target)
        return s;
    else
        return -1;
}


int solve(unordered_map<int, vector<int>>& um, int l, int r, int k){

    if(um.count(k) == 0)
        return 0;

    int rindex = solve1(um[k], r);
    int lindex = solve2(um[k], l);

    if(lindex == -1){
        return 0;
    }
    else
        return rindex - lindex;
}


int main(){


    int n, q;
    unordered_map<int, vector<int>> um;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        um[k].push_back(i);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r, k;
        cin >> l >> r >> k;

        cout << solve(um, l, r, k) << endl;
    }

}