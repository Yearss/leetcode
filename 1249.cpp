
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;



class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int N = s.size();

        int left = 0;
        stack<char> st;

        for(int i = 0; i < N; i++){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')' && left == 0){
                continue;
            }
            else if(s[i] == ')' && left > 0){
                left--;
            }
            
            st.push(s[i]);
        }

        string ret;
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(left > 0 && c == '('){
                left --;
                continue;
            }
            else
                ret.push_back(c);
        }
        reverse(ret.begin(), ret.end());

        return ret;
        
    }
};