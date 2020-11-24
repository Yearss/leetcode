
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    int mem[1001][1001];
    int f(int x, int y, string& s1, string& s2){
        if(mem[x][y] != -1)
            return mem[x][y];
        
        if(x == 0){
            int s = 0;
            for(int i = 1; i <= y; i++){
                s += s2[i - 1];
            }
            mem[x][y] = s;
            return s;
        }
        if(y == 0){
            int s = 0;
            for(int i = 1; i <= x; i++){
                s += s1[i - 1];
            }
            mem[x][y] = s;
            return s;
        } 
        
        int ret = 1e9;
        if(s1[x] == s2[y])
            ret = min(ret, f(x - 1, y - 1, s1, s2));
        else{
            ret = min(ret, f(x - 1, y - 1, s1, s2) + s1[x] + s2[y]);
            ret = min(ret, f(x - 1, y, s1, s2) + s1[x]);
            ret = min(ret, f(x, y - 1, s1, s2) + s2[y]);
        }

        mem[x][y] = ret;

        return ret;
    }
public:
    int minimumDeleteSum(string s1, string s2) {        
        int M = s1.size(), N = s2.size();
        memset(mem, -1, sizeof(mem));

        return f(M, N, s1, s2);
    }
};