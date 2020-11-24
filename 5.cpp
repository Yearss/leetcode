
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

struct pair_hash{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const{
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int solve(vector<vector<pair<int, int>>>& vec){

    unordered_map<pair<int, int>, int, pair_hash> us;

    int ret = -1;
    
    for(int i = 0; i < vec.size(); i++){

        unordered_map<pair<int, int>, int, pair_hash> newUS;
        for(int j = 0; j < vec[i].size(); j++){

            auto fea = vec[i][j];
            if(us.count(fea)){
                newUS[fea] = us[fea] + 1;
            }
            else{
                newUS[fea] = 1;
            }

            ret = max(ret, newUS[fea]);
        }
        us.clear();
        for(auto iter = newUS.begin(); iter != newUS.end(); iter++){
            us.insert(*iter);
        }

    }

    return ret > 1 ? ret: 1;

}

int main(){


    int N,M;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> M;
        vector<vector<pair<int,int>>> vv;
        for(int j = 0; j < M; j++){
            int W;
            cin >> W;
            vector<pair<int,int>> v;
            for(int k = 0; k < W; k++){
                int x, y;
                cin >> x >> y;
                v.push_back(make_pair(x,y));
            }
            vv.push_back(v);
        }
        cout << solve(vv);
    }
}