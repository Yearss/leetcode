
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

// int mem[50000][50000];

// class Solution {
// private:
    
//     int f(int m, int k, vector<int>& weights){

//         cout << "m: " << m << ",k: " << k << endl;

//         if(mem[m][k] != -1)
//             return mem[m][k];

//         if(k == 1){
//             int s = 0;
//             for(int i = 0; i <= m; i++)
//                 s += weights[i];
//             cout << "s: " << s << endl;
//             return s;
//         }

//         int mmin = 1e9;
//         int s = 0;
//         for(int i = 0; i <= m - k + 1; i++){
//             s += weights[m-i];
//             mmin = min(max(f(m - i - 1, k - 1, weights), s), mmin);
//         }

//         mem[m][k] = mmin;

//         cout << "s: "<< mmin << endl;
//         return mem[m][k];

//     }
// public:
//     int shipWithinDays(vector<int>& weights, int D) {
//         memset(mem, -1, sizeof(mem));
//         int N = weights.size();
//         return f(N - 1, D, weights);
//     }
// };


class Solution {
private:
    bool checkValid(vector<int>& weights, int D, int value){
        int days = 0;
        int curW = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] > value)
                return false;
            if(weights[i] + curW <= value){
                curW += weights[i];
            }
            else{
                days++;
                curW = weights[i];
            }
        }
        days++;
        if(days <= D)
            return true;
        else
            return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int s = 0;
        for(int i = 0; i < weights.size(); i++){
            s += weights[i];
        }
        int left = 1, right = s;
        while(left < right){
            int mid = (left + right) / 2;
            // cout << left << ", " << right << endl;
            if(checkValid(weights, D, mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};


int main(){

    vector<int> weights = {3,2,2,4,1,4};

    auto sol = Solution();
    cout << sol.shipWithinDays(weights, 3) << endl;
}