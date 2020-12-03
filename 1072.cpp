
#include <vector>

using namespace std;

class Solution {
public:
    bool check1(vector<int>& v1, vector<int>& v2){
        int n = v1.size();
        for(int i = 0;i < n; i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
    bool check2(vector<int>& v1, vector<int>& v2){
        int n = v1.size();
        for(int i = 0; i < n; i++){
            if(v1[i] + v2[i] != 1)
                return false;
        }
        return true;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int ret = -1e9;
        for(int i = 0; i < m; i++){
            int t = 1;
            for(int j = i + 1; j < m; j++){
                if(check1(matrix[i], matrix[j]) || check2(matrix[i], matrix[j])){
                    t++;
                }
            }
            ret = max(t, ret);
        }
        return ret;
        
    }
};