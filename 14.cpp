

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2){

    if(p1.first > p2.first)
        return true;
    else if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return false;
}

vector<pair<int, int>> solve(vector<pair<int, int>>& vec){

    vector<pair<int, int>> ret;
    sort(vec.begin(), vec.end(), cmp);
    // for(int i = 0; i < vec.size(); i ++){
    //     cout << vec[i].first << " " << vec[i].second << ", ";
    // }
    int n = vec.size();
    pair<int, int> pp = vec[0];
    for(int i = 1; i < n; i++){
        auto p = vec[i];
        if(p.first != pp.first){
            if(ret.size() == 0 || pp.second > ret.back().second){
                ret.push_back(pp);
            }
        }
        pp = vec[i];
    }
    
    if(vec[n - 1].second > ret.back().second)
        ret.push_back(vec[n - 1]);

    reverse(ret.begin(), ret.end());
    return ret;

}



int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    auto ret = solve(vec);
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i].first << ' ' << ret[i].second << endl;

}