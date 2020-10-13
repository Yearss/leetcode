#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        int x = 0, y = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s2[i])
                continue;
            if(s1[i] == 'x')
                x++;
            else
                y++;
        }

        if((x + y) %2 != 0)
            return -1;
        
        return int((x + 1) / 2) + int((y + 1) / 2);
    }
};