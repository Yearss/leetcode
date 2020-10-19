
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    double angleClock(int hour, int minutes) {

        double alpha = 360.0 / (24 * 60) * (hour * 60 + minutes);
        double beta = 360.0 / 60 * minutes;
        
        double angle = abs(alpha - beta);
        return min(angle, 360.0 - angle);
        
    }
};