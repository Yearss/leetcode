

#include <vector>

using namespace std;


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int N = arr.size();
        vector<int> prefixXOR(N + 1);
        for(int i = 1; i <= N; i++){
            prefixXOR[i] = prefixXOR[i-1] ^ arr[i-1];
        }

        N = queries.size();
        vector<int> ret;
        for(int i = 0; i < N; i++){
            ret.push_back(prefixXOR[queries[i][0]] ^ prefixXOR[queries[i][1]+1]);
        }

        return ret;

    }
};