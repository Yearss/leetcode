

#include <vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int> > groupThePeople(vector<int>& groupSizes) {
        
        map<int,vector<int> > m;
        vector<vector<int> > ret;

        int N = groupSizes.size();
        for(int i = 0;i < N; i++){

            int cur = groupSizes[i];
            auto iter = m.find(cur);
            if(iter == m.end()){
                m[cur] = vector<int>();
            }
            else if((iter->second).size() == cur){
                ret.push_back(iter->second);
                m[cur] = vector<int>();
            }
            iter = m.find(cur);
            iter->second.push_back(i);
        }

        // 最后扫描一遍未满的vector
        for(auto iter = m.begin(); iter != m.end(); iter++){
            ret.push_back(iter->second);
        }
        
        return ret;
    }
};