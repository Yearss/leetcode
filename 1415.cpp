
#include <vector>
#include <string>


using namespace std;

class Solution {

private:
    void getHappyStringInner(int i, char preCh, int& k, int n, string& tmp, string& ret){

        if(i == n){
            // 组合完检查是否为第K个
            k--;
            if(k == 0)
                ret = tmp;

        }
        else{
            // 枚举 a,b,c
            if(preCh != 'a'){
                tmp.push_back('a');
                getHappyStringInner(i+1, 'a', k, n, tmp, ret);
                tmp.pop_back();
            }
            if(preCh != 'b'){
                tmp.push_back('b');
                getHappyStringInner(i+1, 'b', k, n, tmp, ret);
                tmp.pop_back();
            }
            if(preCh != 'c'){
                tmp.push_back('c');
                getHappyStringInner(i+1, 'c', k, n, tmp, ret);
                tmp.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string ret, tmp;
        getHappyStringInner(0, 'd', k, n, tmp, ret);

        return ret;
    }
};