
#include <vector>
#include <string>

using namespace std;


class Solution {
private:

    int mem[1005][1005];
    int f(int x, int y, string& s){

        if(mem[x][y] != -1)
            return mem[x][y];

        if(x >= y)
            return 1;
       
        int ret = 0;
        if(s[x] == s[y] && f(x + 1, y - 1, s) == 1)
            ret = 1;

        mem[x][y] = ret;
           
        return mem[x][y];
    }
public:
    int countSubstrings(string s) {


        memset(mem, -1,sizeof(mem));
        int N = s.size();
        int ret = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(f(i, j, s) == 1)
                    ret++;
            }
        }

        return ret;

        
    }
};