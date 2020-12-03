

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string getSmallestString(int n, int k) {

        string ret(n, 'a');
        int p = n - 1;
        while(k > 0){
            
            ret[p] = k > 25 ? 'z' : 
            
        }

    }
};

int main(){

    Solution sol;
    cout << sol.getSmallestString(3, 27);
}