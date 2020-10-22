
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 用栈来维护当前的深度
class Solution {
public:
    int scoreOfParentheses(string s) {

        int N = s.size();
        stack<int> st;
        st.push(0);
        int cur = 0; // 记录当前深度的和
        for(int i = 0; i < N; i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int x = max(st.top() * 2, 1);
                st.pop();
                int y = st.top() + x;
                st.pop();
                st.push(y);
            }
        }

        return st.top();
         
    }
};