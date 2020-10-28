
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;



class Solution {
public:
    priority_queue<int> pq[20001];
    int ul[20001];
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {

        memset(ul, 0, sizeof(ul));

        int ret = 0;
    
        int N = values.size();
        for(int i = 0; i < N; i++){
            pq[labels[i]].push(values[i]);
        }

        while(num_wanted > 0){

            int mmaxIndex = -1;
            int mmax = -1e9;
            for(int i = 0; i < 20001; i++){
                if(pq[i].empty() || ul[i] >= use_limit)
                    continue;
                
                if(pq[i].top() > mmax){
                    mmaxIndex = i;
                    mmax = pq[i].top();
                }
            }

            if(mmaxIndex == -1)
                break;

            pq[mmaxIndex].pop();
            ul[mmaxIndex]++;

            ret += mmax;
            num_wanted --;
        }

        return ret;    

    }
};