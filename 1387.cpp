#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

bool cmp(const pair<int,int>& x, const pair<int,int>& y){
    
    if(x.first < y.first)
        return true;
    else if(x.first == y.first)
        return x.second < y.second;
    else 
        return false;

}


class Solution {

private:
    unordered_map<int,int> mem;
    int getStep(int x){
        
        if(mem.count(x))
            return mem[x];
        
        if(x == 1)
            return 0;

        int ret;
        if(x % 2 == 0)
            ret = getStep(x / 2) + 1;
        if(x % 2 == 1)
            ret = getStep(x * 3 + 1) + 1;

        mem[x] = ret;

        return ret;
    }

public:
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>> vec;
        for(int i = lo; i <= hi; i++){
            vec.push_back(make_pair(getStep(i), i));
        }

        sort(vec.begin(), vec.end(), cmp);

        return vec[k-1].second;

    }
};