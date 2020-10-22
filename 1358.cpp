
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int N = s.size();
        int ret = 0;
        unordered_map<char,int> um;
        for(int i = 0, j = 0;i < N; i++){
            while(j < N && um.size() < 3){
                um[s[j]] = um[s[j]] + 1;
                j++;
            }
            if(um.size() == 3)
                ret += N - j + 1;
            if(um[s[i]] == 1)
                um.erase(s[i]);
            else
                um[s[i]] = um[s[i]] - 1;
        }

        return ret;
    }
};