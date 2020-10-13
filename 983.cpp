#include <vector>


using namespace std;


class Solution {

private:
    int mem[400];
    int f(int x, vector<int>& days, vector<int>& cost){

        int N = days.size();

        if(x == N)
            return 0;
        
        if(mem[x] != -1)
            return mem[x];
        
        int mmin = 1e9;
        
        // 选择1天
        mmin = min(f(x + 1, days, cost) + cost[0], mmin);

        // 选择7天
        int y = x + 1;
        while(y < N && days[x] + 7 > days[y])
            y++;
        mmin = min(f(y, days, cost) + cost[1], mmin);

        // 选择30天
        y = x + 1;
        while(y < N && days[x] + 30 > days[y])
            y++;
        mmin = min(f(y, days, cost) + cost[2], mmin);

        mem[x] = mmin;
        return mem[x];

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        memset(mem, -1, sizeof(mem));
        return f(0, days, costs);

    }
};