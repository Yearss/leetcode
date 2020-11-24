
#include <vector>


using namespace std;

class Solution {
private:
    int f(vector<int>& ps, int L, int M, int N){
        int ret = 0;
        // 枚举两个点
        for(int i = 1; i <= N - L - M + 1; i++){
            for(int j = i + L; j <= N - M + 1; j++){
                
                int sum = ps[i + L - 1] - ps[i - 1] + ps[j + M - 1] - ps[j - 1];
                ret = max(sum, ret);
            }
        }
        return ret;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {

        int N = A.size();

        // 前缀和
        vector<int> ps(1001, 0);
        for(int i = 1; i <= N; i++){
            ps[i] = ps[i - 1] + A[i - 1];
            cout << ps[i] << endl;
        }

        int ret = 0;
        ret = max(f(ps, L, M, N), ret);
        ret = max(f(ps, M, L, N), ret);

        return ret;
    }
};

// O(N)

class Solution {
private:
    int maxSumTwoNoOverlapInner(vector<int>& A, vector<int>& ps, int L, int M){
        int ret = -1e9;
        
        int l[1001], m[1001];
        memset(l, 0, sizeof(l));
        memset(m, 0, sizeof(m));

        int N = A.size();
        for(int i = 1; i <= N; i++){
            if(i < L)
                l[i] = -1e9;
            else if(i == L)
                l[i] = ps[i] - ps[i - L];
            else{
                l[i] = max(l[i - 1], ps[i] - ps[i - L]);
            }
        }
        for(int i = N; i >= 1; i--){
            if(N - i + 1 < M)
                m[i] = -1e9;
            else if(N - i + 1 == M)
                m[i] = ps[i + M - 1] - ps[i - 1];
            else{
                m[i] = max(m[i + 1], ps[i + M - 1] - ps[i - 1]);
            }
        }

        // 枚举分界点
        for(int i = 1; i < N; i++){
            ret = max(l[i] + m[i + 1], ret);
        }

        return ret;

    }
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        
        int N = A.size();
        vector<int> ps(N + 1, 0);

        for(int i = 0; i < N; i++){
            ps[i + 1] = ps[i] + A[i];
        }

        int x = maxSumTwoNoOverlapInner(A, ps, L, M);
        int y = maxSumTwoNoOverlapInner(A, ps, M, L);
        return max(x, y);
    }
};