
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        stack<int> st1, st2;
        int N = seq.size();
        vector<int> ret(N);
        for(int i = 0; i < N; i++){
            if(seq[i] == '('){
                st1.push(i);
                while(!st2.empty())
                    st2.pop();
            }
            else{
                
                if(st1.size() > st2.size()){
                    auto t = st1.top();
                    ret[t] = 1;
                    ret[i] = 1;
                }

                st1.pop();
                st2.push(i);

            }
        }

        return ret;
    }
};