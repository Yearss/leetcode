

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    int numSplits(string s) {
        

        unordered_map<char, int> left, right;
        int N = s.size();
        for(int i = 0; i < N; i++){
            right[s[i]] = right[s[i]] + 1;
        }

        int ret = 0;
        // 枚举分割点
        for(int i = 1; i < N - 1; i++){
            left[s[i]] = left[s[i]] + 1;
            right[s[i]] = right[s[i]] - 1;
            if(right[s[i]] == 0){
                right.erase(right.find(s[i]));
            }
            if(left.size() == right.size())
                ret ++;
        }

        return ret;

    }
};