#include <vector>


using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int s = 0;
        for(int i = 0; i < nums.size(); i++)
            s = s ^ nums[i];

        s = s & -s;

        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if((s & nums[i]) == 0)
                a = a ^ nums[i];
            else
                b = b ^ nums[i];
        }

        return {a, b};
        
    }
};