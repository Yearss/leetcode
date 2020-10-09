

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>  


using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        
        int N = s.size();
        stack<char> st;
        for(int i = 0; i < N; i++){
            if(s[i] == ')'){
                queue<char> que;
                while(!st.empty() && st.top() != '('){
                    auto v = st.top();
                    st.pop();
                    que.push(v);
                }
                st.pop();
                while(!que.empty()){
                    st.push(que.front());
                    que.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }   
        
        reverse(ret.begin(), ret.end());
        return ret;

    }
};