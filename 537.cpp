#include <string>
#include <utility>
#include <sstream>


using namespace std;

class Solution {

private:
    pair<int,int> decode(string& str){
        int N = str.size();
        pair<int,int> ret;
        for(int i = 0; i < N; i++){
            if(str[i] == '+'){
                ret = {stoi(str.substr(0, i)), stoi(str.substr(i+1, N))};
            }
        }

        return ret;
    }

public:
    string complexNumberMultiply(string a, string b) {
        
        auto x = decode(a), y = decode(b);

        int z = x.first * y.first - x.second * y.second;
        int w = x.first * y.second + x.second * y.first;

        std::ostringstream ss;
        ss << z << "+" << w << "i";

        return ss.str();



    }
};