
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
private:
    string i2s(int n){
        
        string ret;
        while(n > 0){
            char bit = (n & 1) == 1 ? '1' : '0';
            ret.push_back(bit);
            n = n >> 1;
        }

        return ret;

    }
public:
    bool queryString(string S, int N) {

        // 存储所有字符串
        reverse(S.begin(), S.end());
        int n = S.size();
        unordered_set<string> us;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                us.insert(S.substr(i, j - i + 1));
            }
        }

        // 枚举N
        for(int n = 1; n <= N; n++){
            auto str = i2s(n);
            if(!us.count(str))
                return false;
        }
        return true;
    }
};


class Solution {
private:
    string i2s(int n){
        
        string ret;
        while(n > 0){
            char bit = (n & 1) == 1 ? '1' : '0';
            ret.push_back(bit);
            n = n >> 1;
        }

        return ret;

    }
public:
    bool queryString(string S, int N) {

        // 枚举N
        reverse(S.begin(), S.end());
        for(int n = 1; n <= N; n++){
            auto str = i2s(n);
            if(S.find(str) == S.npos)
                return false;
        }
        return true;
    }
};