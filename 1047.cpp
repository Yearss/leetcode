#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size();
        string ret;
        stack<int> st;
        for(int i = 0; i < n; i++){

            if(ret.empty() || s[i] != ret.back()){
                ret.push_back(s[i]);
                st.push(1);
            }
            else if(ret.back() == s[i] &&  st.top() < k - 1){
                st.push(st.top() + 1);
                ret.push_back(s[i]);
            }
            else{
                while(!ret.empty() && ret.back() == s[i]){
                    ret.pop_back();
                    st.pop();
                }
            }
        }

        return ret;   
    }

};

int main(){

    string s = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy";
    int k = 4;
    Solution sol;
    cout << sol.removeDuplicates(s, 4);
}