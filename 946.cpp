
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int N = pushed.size();
        stack<int> st;
        int x = 0;
        for(int i = 0; i < N; i++){
            if(pushed[i] != popped[x])
                st.push(pushed[i]);
            else{
                x++;
                while(!st.empty() && x < popped.size() && st.top() == popped[x]){
                    st.pop();
                    x++;
                }
            }
        }

        N = popped.size();
        for(int i = x; i < N; i++){
            if(popped[i] != st.top())
                return false;
            else
                st.pop();
        }

        return true;


    }
};