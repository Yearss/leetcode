
#include <vector>

using namespace std;


class Solution {
private:
    vector<int> quickSort(vector<int>& nums){

        int N = nums.size();
            
        if(N < 1)
            return nums;

        int pivot = nums[0];    
            
        vector<int> left, right;
        for(int i = 1; i < N; i++){
            if(nums[i] <= pivot)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        auto leftRet = quickSort(left);
        auto rightRet = quickSort(right);

        vector<int> ret(leftRet.begin(), leftRet.end());
        ret.push_back(pivot);
        ret.insert(ret.end(), rightRet.begin(), rightRet.end());
        return ret;
    }
public:
    vector<int> sortArray(vector<int>& nums) {

        return quickSort(nums);
    }
};