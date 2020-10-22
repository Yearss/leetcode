
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
private:
    int gcd(int x, int y){
        if(y == 0)
            return x;
        else
            return gcd(y, x%y);
    }
public:
    vector<string> simplifiedFractions(int n) {
        
        vector<string> ret;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(gcd(i, j) == 1){
                    ostringstream oss;
                    oss << i << "/" << j;
                    ret.push_back(oss.str());
                }
            }
        }

        return ret;
    }
};