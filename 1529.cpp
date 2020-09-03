

#include <vector>
#include <string>
#include <stack>


using namespace std;




class Solution {
public:
    int minFlips(string target) {

        int N = target.size(), ret = 0;
        stack<char> st;
        st.push('0');

        for(int i = 0; i < N; i++){
            if(target[i] != st.top())
                st.push(target[i]);
        }

        return st.size() - 1;
          
    }
};


class Solution {
public:
    int minFlips(string target) {

        int N = target.size(), ret = 0;

        for(int i = 1; i < N; i++){
            if(target[i] != target[i-1])
                ret++;
        }
        if(target[0] == '0')
            return ret;
        else
            return ret + 1;
          
    }
};