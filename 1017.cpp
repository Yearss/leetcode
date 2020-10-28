

#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string baseNeg2(int N) {

        string ret;
        
        while(N > 0){
            int y = N % (-2);
            int x = N / (-2);
            
            if(y >= 0){
                char c = (y == 0 ? '0' : '1');
                ret.push_back(c);
            }
            else{
                y = y + 2;
                char c = (y == 0 ? '0' : '1');
                ret.push_back(c);
                x += 1;
            }
            N = x;
        }

        reverse(ret.begin(), ret.end());

        return ret;
        
    }
};