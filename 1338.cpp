
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> um;
        int N = arr.size();
        for(int i = 0; i < N; i++)
            um[arr[i]] = um[arr[i]] + 1; 
    
        vector<int> vec;
        for(auto iter = um.begin(); iter != um.end(); iter++)
            vec.push_back(iter->second);
        
        sort(vec.begin(), vec.end());
        int k = 0, ret = 0;
        for(auto iter = vec.rbegin(); iter != vec.rend(); iter++){
            k += *iter;
            ret ++;
            if(k >= N / 2)
                break;
        }

        return ret;

    }
};