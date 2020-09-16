
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


// TLE
class Solution {

private:

    bool used[2000];
    bool checkValid(vector<vector<int>>& ret, vector<int> cur){
        int k = 0;
        for(int i = 0; i < ret.size(); i++){
            if(ret[i][0] >= cur[0])
                k++;
        }
        
        return cur[1] == k;
    }
    bool dfs(int x, int n, vector<vector<int>>& ret, vector<vector<int>>& people){
        
        if(x < n){
            for(int i = 0; i < n; i++){
                
                if(used[i])
                    continue;

                if(checkValid(ret, people[i])){
                    ret.push_back(people[i]);
                    used[i] = true;
                    if(dfs(x+1, n, ret, people))
                        return true;
                    used[i] = false;
                    ret.pop_back();
                }
            }
            return false;
        }
        return true;
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        int N = people.size();
        vector<vector<int>> ret;
        memset(used, 0, sizeof(used));
        dfs(0,N, ret, people);

        return ret;
             
    }
};


bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] < b[0])
        return true;
    else if(a[0] == b[0] && a[1] > b[1])
        return true;
    else
        return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), cmp);
        int N = people.size();
        vector<vector<int>> ret;
        for(int i = 0; i < N; i++){
            ret.insert(ret.begin() + people[i][1], people[i]);
        }

        return ret;

    }
};