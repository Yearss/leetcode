

#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

// TLE
class Solution {
private:
    void dfs(vector<int>& finn, int x, int tmpSum, int& k, int tmpCnt, int& ret){

        if(tmpSum == k && tmpCnt < ret){
            ret = tmpCnt;
        }

        if(x < 0){
            return ;
        }
        else{
            if(finn[x] + tmpSum <= k && tmpCnt + 1 < ret)
                dfs(finn, x - 1, tmpSum + finn[x], k, tmpCnt + 1, ret);
            
            dfs(finn, x - 1, tmpSum, k, tmpCnt, ret);
        }

    }
public:
    int findMinFibonacciNumbers(int k) {

        vector<int> finn = {1, 1};
        // 构造Finnaboic
        int n = 2, s = 1;
        while(s < k){
            s = finn[n - 1] + finn[n - 2];
            finn.push_back(s);
            n++;
        }

        int ret = 1e9;
        dfs(finn, n - 1, 0, k, 0, ret);

        return ret;
    }
};

// DP

class PairHash{
public:
    int operator()(const pair<int,int>& p) const{
        auto h1 = hash<int>()(p.first);
        auto h2 = hash<int>()(p.second);

        return h1^h2;
    }
};

// TLE ????
class Solution {
private:
    const int INF = 1e9;
    unordered_map<pair<int,int>, int, PairHash> mem;
    int f(int x, int y, vector<int>& finn, vector<long>& prefixSum){
        const auto key = make_pair(x, y);
        if(mem.count(key)){
            return mem[key];
        }

        if(y == 0)
            return 0;
        if(x < 0 || y < 0)
            return INF;
        if(prefixSum[x+1] < y)
            return INF;


        int A = f(x - 1, y - finn[x], finn, prefixSum) + 1;
        int B = f(x - 1, y, finn, prefixSum);
        
        mem[key] = min(A, B);

        return mem[key];

    }
public:
    int findMinFibonacciNumbers(int k) {
        
        vector<int> finn = {1, 1};
        // 构造Finnaboic
        int n = 2, s = 1; 
        while(s < k){
            s = finn[n - 1] + finn[n - 2];
            finn.push_back(s);
            n++;
        }

        vector<long> prefixSum = {0};
        for(int i = 0; i < finn.size(); i++){
            prefixSum.push_back(prefixSum[i] + finn[i]);
        }
        
        return f(n - 1, k, finn, prefixSum);

    }
};



