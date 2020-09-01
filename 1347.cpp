
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        
        // 计算s
        vector<int> index(50);
        int N = s.size();
        for(int i = 0; i < N; i++){
            index[s[i] - 'a']++;
        }

        // 遍历t
        int ret = 0;
        for(int i = 0; i < N; i++){
            int c = t[i] - 'a';
            if(index[c] > 0){
                index[c]--;
            }
            else{
                ret++;
            }
        }

        return ret;
    }
};