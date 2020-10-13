
#include <vector>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int x = -1, N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[i] == 1){
                if(x != -1 && i - x <= k){
                    return false;
                }
                else{
                    x = i;
                }
            }
        }

        return true;
        
    }
};