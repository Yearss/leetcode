
#include <vector>
#include <algorithm>

using namespace std;

// almost TLE
class Solution {

private:
    int mem[50][50];
    int mctFromLeafValuesInner(vector<int>& arr, int start, int end){

        if(mem[start][end] >= 0)
            return mem[start][end];
        
        if(end - start == 1)
            return 0;

        int mmin = 1e9;
        for(int i = start + 1; i < end; i++){
        
            int leftMax = *max_element(arr.begin()+start, arr.begin()+i);
            int rightMax = *max_element(arr.begin()+i, arr.begin()+end);
            int leftRet = mctFromLeafValuesInner(arr, start, i);
            int rightRet = mctFromLeafValuesInner(arr, i, end);

            mmin = min(mmin, leftRet + rightRet + leftMax * rightMax);
            
        }

        mem[start][end] = mmin;
        return mmin;

    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        memset(mem, -1, sizeof(mem));
        int ret = mctFromLeafValuesInner(arr, 0, arr.size());

        return ret;

    }
};