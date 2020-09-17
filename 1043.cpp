

#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int N = arr.size(),f[550];
       
        if(k > N){
            return (*max_element(arr.begin(), arr.end())) * N;
        }
        else {
            int mmax = -1;
            for(int i = 0; i < k; i++){
                mmax = max(mmax, arr[i]);
                f[i] = mmax * (i + 1);
            }

            for(int i = k; i < N; i++){
                int mmax = -1;
                f[i] = -1;
                for(int j = 1; j <= k; j++){
                    mmax = max(arr[i-j+1], mmax);
                    f[i] = max(f[i], f[i-j] + mmax * j);
                }
            }
            return f[N - 1];
        }
        
    }
};