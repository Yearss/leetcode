
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, unordered_set<int>> um;
        unordered_map<int, int> num2cnt;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            num2cnt[nums[i]] = num2cnt[nums[i]] + 1;
        }

        for(auto iter = num2cnt.begin(); iter != num2cnt.end(); iter++){
            int num = iter->first;
            int cnt = iter->second;
            um[cnt].insert(num);
        }

        vector<int> ret;
        for(int i = N; i > 0; i--){
            int x = um[i].size();
            k = k - x;
            if(k >= 0){
                for(auto iter = um[i].begin(); iter != um[i].end(); iter++)
                    ret.push_back(*iter);
            }
        }

        return ret;
    }
};