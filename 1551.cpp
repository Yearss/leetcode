
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        return  n * (n / 2) - (n / 2) * (n / 2);
    }
};

n = 7
1,3,5,7,9,11,13

x = n 


1,3,5,7,9,11


m = 取整(n / 2) = 1

n * m - m^2


0 1 2 3 4 5   6

n = 7 = [13 / 2]
p = 7 / 2 
x = 7

i = 1; x - i  
i = 3; x - i;
i = 5; x - i 
3 * x - (1 + 3 + 5) = 21 - 9 = 12

(1 + 3 + ... n) = (n + 1) * (n + 1) / 4