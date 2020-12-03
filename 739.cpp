

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        int n = T.size();
        stack<int> st;
        st.push(n - 1);
        vector<int> ret(n);
        for(int i = n - 2; i >= 0; i --){
            while(!st.empty() && T[i] >= T[st.top()]){
                st.pop();
            }
            if(st.empty())
                ret[i] = 0;
            else
                ret[i] = st.top() - i;
            st.push(i);
        }

        return ret;
    }
};