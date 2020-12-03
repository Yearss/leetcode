

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(vector<int>& vec){

    
    if(vec.empty())
        return true;

    int cnt = count(vec.begin(), vec.end(), vec[0]);
    if(vec.size() % 3 > 0 && cnt >= 2){
        vector<int> new_vec(vec.begin() + 2, vec.end());
        if(check(new_vec))
            return true;
    }

    if(cnt >= 3){
        vector<int> new_vec(vec.begin() + 3, vec.end());
        if(check(new_vec))
            return true;
    }

    if(count(vec.begin() + 1, vec.end(), vec[0] + 1) > 0 && count(vec.begin() + 1, vec.end(), vec[0] + 2) > 0){
        vector<int> new_vec(vec.begin() + 1, vec.end());
        new_vec.erase(find(new_vec.begin(), new_vec.end(), vec[0] + 1));
        new_vec.erase(find(new_vec.begin(), new_vec.end(), vec[0] + 2));
        if(check(new_vec))
            return true;
    }

    return false;

}

vector<int> solve(vector<int>& vec){

    vector<int> ret;
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < vec.size(); i++){
        cnt[vec[i]]++;
    }
    for(int i = 1; i < 10; i++){
        if(cnt[i] < 4){
            vector<int> new_vec(vec.begin(), vec.end());
            new_vec.push_back(i);
            sort(new_vec.begin(), new_vec.end());
            if(check(new_vec)){
                ret.push_back(i);
                // cout << "ret:" << i << " ";
            }
        }
    }

    if(ret.empty())
        ret.push_back(0);
    return ret;
}

int main(){

    vector<int> vec;
    for(int i = 0; i < 13; i++){
        int t;
        cin >> t;
        vec.push_back(t);
    }
    auto ret = solve(vec);
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";
}
