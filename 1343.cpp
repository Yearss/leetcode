
#include <vector>

using namespace std;


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int ret = 0, N = arr.size();
        vector<int> prefixSum = {0};
        for(int i = 0; i < N; i++)
            prefixSum.push_back(prefixSum[i] + arr[i]);

        //枚举起点
        for(int i = 0; i < N; i++){
            if(i + k - 1< N && (prefixSum[i + k] - prefixSum[i]) * 1.0 / k > threshold ){
                ret ++;
            }
        }
        
        return ret;
    }
};