
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        vector<int> diff;
        int n = A.size();
        for(int i = 0; i < n - 1; i++){
            diff.push_back(A[i + 1] - A[i]);
        } 
        n = diff.size();
        int p = 0, i = 1, ret = 0;
        while(i < n){
            while(i < n && diff[i] == diff[p])
                i++;
            int x = i - p;
            ret += x * (x - 1) / 2;
            p = i;
            i++;
        } 
        return ret;
    }
};

int main(){

    vector<int> A = {1, 2, 3, 4};
    Solution sol;
    cout << sol.numberOfArithmeticSlices(A);
}