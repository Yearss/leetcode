

#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> ret;
        ret.push_back(0);
        for(int i = 1; i <= num; i++){
            int x = ret[i - int(pow(2, int(log2(i))))] + 1;
            ret.push_back(x);
        }
        
        return ret;
    }
};