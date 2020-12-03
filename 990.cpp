
#include <vector>
#include <iostream>

using namespace std;


int parent[30];
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        for(char c = 'a'; c <= 'z'; c++){
            parent[c - 'a'] = c - 'a';
        }

        int n = equations.size();
        for(int i = 0; i < n; i++){
            if(equations[i][1] == '='){
                uni(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }

        for(int i = 0; i < n; i++){
            if(equations[i][1] == '!'){
                if(find(equations[i][0] - 'a') == find(equations[i][3] - 'a'))
                    return false;
            }
        }

        return true;


    }
    
    int find(int x){
        while(parent[x] != x)
            x = parent[x];

        return x;
    }
    void uni(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py)
            parent[px] = py;
    }
};

int main(){

    vector<string> vec = {"a==b","b==c","a==c"};
    Solution sol;
    cout << sol.equationsPossible(vec);
}