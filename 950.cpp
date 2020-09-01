#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(), deck.end(), less<int>());
        vector<int> ret;
        queue<int> que;
        int N = deck.size();
        
        if(N == 0)
            return ret;
        
        que.push(deck[N - 1]);

        for(int i = N - 2; i >= 0; i--){
            int x = que.front();
            que.pop();
            que.push(x);
            que.push(deck[i]);
        }
        
        ret.resize(N);
        int i = N - 1;
        while(!que.empty()){
            ret[i--] = que.front();
            que.pop();
        }

        return ret;
    }
};

