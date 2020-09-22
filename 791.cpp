
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;




class Solution {
public:
    string customSortString(string S, string T) {

        string ret;
        unordered_map<char,int> um;
        for(int i = 0; i < T.size(); i++)
            um[T[i]] = um[T[i]] + 1;

        for(int i = 0; i < S.size(); i++){
            if(um.count(S[i])){
                for(int j = 0; j < um[S[i]]; j++)
                    ret.push_back(S[i]);
                um.erase(um.find(S[i]));
            }
        }

        for(auto iter = um.begin(); iter != um.end(); iter++){
            for(int i = 0; i < iter->second; i++)
                ret.push_back(iter->first);
        }

        return ret;
   
    }
};


