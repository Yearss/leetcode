#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    bool checkIfCanBreakInner(string& s1, string& s2){
        int N = s1.size();
        for(int i = 0; i < N; i++){
            if(s1[i] < s2[i])
                return false;
        }
        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return checkIfCanBreakInner(s1, s2) || checkIfCanBreakInner(s2, s1);
        


    }
};