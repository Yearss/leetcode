
#include <vector>

using namespace std;



class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int N = A.size();
        static int f[20005][20005];

        memset(f, 0, sizeof(f));

        //初始化
        int x = 0;
        for(int i = 1; i <= N; i++){

            if(A[i - 1] == 1){
                x ++;
                f[i][0] = x;
            }
            else{
                x = 0;
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= K; j++){
                if(A[i - 1] == 1){
                    f[i][j] = f[i - 1][j] + 1;
                }
                else{
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
            }
        }

        int ret = -1e9;
        for(int i = 0; i <= N; i++){
            ret = max(f[i][K], ret);
        }
        
        return ret;
    }
};

// O(n)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {

        int n = A.size();
        int ret = 0;
        for(int i = 0, j = 0; i < n; i++){
            while(j < n){
                if(A[j] == 0 && K == 0)
                    break;
                else if(A[j] == 0)
                    K --;
                j++;
            }

            ret = max(ret, j - i);

            if(A[i] == 0)
                K++;
        }

        return ret;
    }
};