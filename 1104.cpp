

#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        vector<int> ret;
        ret.push_back(label);

        while(label != 1){
            int level = int(log2(label)) + 1;
            if(level % 2 == 0){
                int x = int(pow(2, level-1)) + int(pow(2, level)) - 1 - label;
                label = x / 2;
            }
            else{
                int x = label / 2;
                level--;
                label =  int(pow(2, level-1)) + int(pow(2,level)) - 1 - x; 
            }
            ret.push_back(label);
        }
        vector<int> rett (ret.rbegin(), ret.rend());
        return rett;

    }
};