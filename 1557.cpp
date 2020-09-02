#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

// 5
// [[1,3],[2,0],[2,3],[1,0],[4,1],[0,3]]
class Solution {

public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        

        // 构造邻接表，构造可达表
        vector<int> inDegree(n);
        
        for(int i = 0; i < edges.size(); i ++){
           inDegree[edges[i][1]] ++;
        }

        vector<int> ret;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0)
                ret.push_back(i);
        }
        
        return ret;

    }
};