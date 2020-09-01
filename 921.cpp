
#include <string>
#include <vector>

using namespace std;

// TLE
class Solution {

private:
    int mem[2000][2000];
    
    int dp(int i, int j, string& S){
        if(mem[i][j] != -1)
            return mem[i][j];
        
        int ret;
        if(i == j)
            ret = 1;
        else if(i > j)
            ret = 0;
        else {
            if(S[j-1] == '(')
                ret = dp(i, j-1, S) + 1;
            else{
                int mim = j - i + 1;
                for(int m = i; m < j; m++){
                    if(S[m-1] == '('){
                        auto t = dp(i, m-1, S) + dp(m+1, j-1, S);
                        if(t < mim)
                            mim = t;
                    }
                }
                ret = mim;
            }
        }
        mem[i][j] = ret;

        return mem[i][j];  
    }
public:
    int minAddToMakeValid(string S) {
        
        memset(mem, -1, sizeof(mem));
        int N = S.size();
        int ret = dp(1, N, S);

        return ret;


    }
};

// O(n)
class Solution {

public:
    int minAddToMakeValid(string S) {
        
        int ret = 0;
        int left[2000], right[2000], N = S.size();
        int a = 0, b = 0;
        for(int i = 0; i < N; i++){
            if(S[i] == '(')
                a++;
            else
                b++;
            left[i] = a;
            right[i] = b;
        }
        for(int i = 0; i < N; i++){
            if(S[i] == '(')
                ret ++;
            else{
                ret = abs(right[i] - left[i]);
            }
        }

        return ret;
    }
};