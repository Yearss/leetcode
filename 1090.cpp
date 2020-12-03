
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {

        unordered_map<int, vector<int>> um;
        for(int i = 0; i < values.size(); i++){
            um[values[i]].push_back(labels[i]);
        }

        sort(values.begin(), values.end());

        int ret = 0;
        unordered_map<int, int> label2cnt;
        for(int i = 0; i < values.size(); i+=){

            
            if(label2cnt[labels[i]] > 0){

            }
        }

        

    }
};