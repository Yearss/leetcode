

#include <vector>
#include <string>

using namespace std;

class Solution {

public:
    vector<string> printVertically(string s) {

        int N = s.size();
        int x = 0, y = 0, cl = -1;
        char arr[201][201];
        memset(arr, ' ', sizeof(arr));
        for(int i = 0; i < N; i++){
            if(s[i] == ' '){
                x++;
                y = 0;
                continue;
            }
            cl = max(y, cl);
            arr[x][y] = s[i];
            y++;
            
        }

        vector<string> ret;
        for(int j = 0; j <= cl; j++){
            int i = x;
            while(arr[i][j] == ' '){
                i--;
            }
            if(i >= 0){
                string str;
                while(i >= 0)
                    str.push_back(arr[i--][j]);
                reverse(str.begin(), str.end());
                ret.push_back(str);
            }
        }

        return ret;
    
    }
};