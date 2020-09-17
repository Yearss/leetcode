#include <vector>
#include <string>

using namespace std;

class BrowserHistory {
private:
    vector<string> urls;
    int curIndex;
    int N;
public:
    BrowserHistory(string homepage) {
        urls.resize(5100);
        curIndex = -1;
        urls[++curIndex] = homepage;
        N = 1;
    }
    
    void visit(string url) {
        urls[++curIndex] = url;
        N = curIndex + 1;
    }
    
    string back(int steps) {
        if(steps > curIndex){
            curIndex = 0;
            return urls[0];
        }
        else{
            curIndex = curIndex - steps;
            return urls[curIndex];
        }
    }
    
    string forward(int steps) {
        if(curIndex + steps < N){
            curIndex = curIndex + steps;
            return urls[curIndex];
        }
        else {
            curIndex = N - 1;
            return urls[N - 1];
        }
    }
};
