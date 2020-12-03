

#include <vector>
#include <iostream>
#include <queue>


using namespace std;

class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        
        queue<int> que;
        vector<int> ret;
        for(int i = 1; i < 10; i++){
            que.push(i);
        }
    
        while(!que.empty()){
            int x = que.front();
            que.pop();
            if(x <= high && x >= low){
                ret.push_back(x);
            }
            if(x <= high){
                if(x % 10 < 9)
                    que.push(x * 10 + x % 10 + 1);
            }
        }

        return ret;

    }
};

int main(){
    Solution sol;
    auto ret = sol.sequentialDigits(1000, 13000);
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << ' ';
}