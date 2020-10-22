
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// TLE
class Solution {
public:
    int findTheLongestSubstring(string s) {

        
        int N = s.size(), ret = -1;
        for(int i = 0; i < N; i++){
            unordered_set<char> us;
            for(int j = i; j < N; j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                    if(us.count(s[j])){
                        us.erase(s[j]);
                    }
                    else{
                        us.insert(s[j]);
                    }
                }
                
                if(us.empty()){
                    ret = max(j - i + 1, ret);
                }
            }
        }
        
        return ret;
    }
};


class Solution {
public:
    int findTheLongestSubstring(string s) {

        int N = s.size(), ret = 0;
        unordered_map<int, int> um;
        int cur = 0;
        um[cur] = -1;
        for(int i = 0; i < N; i++){
            if(s[i] == 'a')
                cur = cur ^ 1;
            else if(s[i] == 'e')
                cur = cur ^ (1 << 1);
            else if(s[i] == 'i')
                cur = cur ^ (1 << 2);
            else if(s[i] == 'o')
                cur = cur ^ (1 << 3);
            else if(s[i] == 'u')
                cur = cur ^ (1 << 4);

            if(um.count(cur)){
                ret = max(ret, i - um[cur]);
            }
            else{
                um[cur] = i;
            }
            
        }

        return ret;

    }
};