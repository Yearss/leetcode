
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;


struct pair_hash{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const{
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        int N = orders.size();
        set<string> s1;
        set<int> s2;
        unordered_map<pair<int, string>, int, pair_hash> um;
        for(int i = 0; i < N; i++){

            s1.insert(orders[i][2]);
            s2.insert(stoi(orders[i][1]));

            auto key = make_pair(stoi(orders[i][1]), orders[i][2]);
            um[key] = um[key] + 1;
        }

        // cout
        vector<string> header(s1.begin(), s1.end());
        header.insert(header.begin(), "Table");

        vector<vector<string>> ret;
        ret.push_back(header);
        for(auto iter1 = s2.begin(); iter1 != s2.end(); iter1++){
            vector<string> tmp = {to_string(*iter1)};
            for(auto iter2 = s1.begin(); iter2 != s1.end(); iter2++){
                auto key = make_pair(*iter1, *iter2);
                tmp.push_back(to_string(um[key]));
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};