
#include <vector>

using namespace std;


class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        const int MOD = 1e9 + 7;
        vector<int> nArr;
        int s1 = 0, s2;
        for(int i = 0; i < n; i++){
            s2 = s1;
            for(int j = i; j < n; j++){
                s2 += nums[j];
                nArr.push_back(s2 - s1);
            }
            s1 += nums[i]; 
        }

        sort(nArr.begin(), nArr.end());

        long ret = 0;
        for(int i = left; i <= right; i++)
            ret += nArr[i-1];

        return ret % MOD;
    
    }
};