


#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
private:
    unordered_map<int, double> mem;
    double f(int x, int n){
        
        if(mem.count(x))
            return mem[x];
        
        if(x == 1)
            return 0.0;

        double s = 1.0 / n;
        for(int i = 2; i < x; i++){
            double p = f(i, n) / (n - i);
            s += p;
        }

        mem[x] = s;
        return s;
    } 
public:
    double nthPersonGetsNthSeat(int n) {
        
        double ret = f(n, n);

        return 1 - ret;
    }
};