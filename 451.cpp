
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool comp(pair<char,int>& p1, pair<char,int>& p2){
    
    return p1.second > p2.second;
}

class Solution {
public:
    string frequencySort(string s) {
        int N = s.size();
        unordered_map<char, int> um;

        for(int i = 0; i < N; i++){
            um[s[i]] = um[s[i]] + 1;
        }   

        vector<pair<char,int>> vec(um.begin(), um.end());
        
        sort(vec.begin(), vec.end(), comp);
        string ret;
        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < vec[i].second; j++)
                ret.push_back(vec[i].first);
        }

        return ret;

    }
};