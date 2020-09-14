
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ret;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[abs(nums[i])-1] < 0)
                ret.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
        }

        return ret;
      
    }
};