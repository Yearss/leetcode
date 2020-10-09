#include <vector>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        
        
        int N = light.size(), yellow = 0, ret = 0;
        vector<int> isOn(N+1, 0); 
        for(int i = 0, j = 0; i < N; i++){
            isOn[light[i]] = 1;
            yellow++;
            if(j + 1 == light[i]){
                yellow--;
                j = j + 1;
                while(j < N && isOn[j + 1] == 1){
                    j++;
                    yellow--;
                }
            }

            if(yellow == 0)
                ret++;   
        }

        return ret;
    }
};