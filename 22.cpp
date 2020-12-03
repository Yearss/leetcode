
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(){

    string str = "[[[1,2,3],[2,3,4]],[[2,3,4],[3,4,5]],[[3,4,5],[4,5,6]]]";

    int n = str.size();
    vector<int> ret(100);
    stack<int> st;
    int mmax = -1e9;
    for(int i = 0; i < n; i++){
        if(str[i] == '['){
            st.push(str[i]);
            int m = st.size();
            mmax = max(m, mmax);
            ret[m - 1] = 1;
        }
        else if(str[i] == ']'){
            st.pop();
        }
        else if(str[i] == ','){
            ret[st.size() - 1]++;
        }
    }

    for(int i = 0; i < mmax; i++){
        cout << ret[i] << ' ';
    }
}