
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {

private:
    void dfs(int x, vector<string>& ret, string& temp, string& s){
        if(x == s.size()){
            ret.push_back(temp);
        }
        else{

            temp.push_back(s[x]);
            dfs(x + 1, ret, temp, s);
            temp.pop_back();

            if(s[x] >= 'a' && s[x] <= 'z'){
                temp.push_back(toupper(s[x]));
                dfs(x + 1, ret, temp, s);
                temp.pop_back();
            }
            if(s[x] >= 'A' && s[x] <= 'Z'){
                temp.push_back(tolower(s[x]));
                dfs(x + 1, ret, temp, s);
                temp.pop_back();
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> ret;
        string temp;
        dfs(0, ret, temp, S);

        return ret;
        
        
    }
};