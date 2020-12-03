
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        int n = nums.size();
        vector<int> oddSum(n, 0), evenSum(n, 0);
        for(int i = 0; i < n; i++){
            
            if(i % 2 == 0){
                evenSum[i] = i > 0 ? evenSum[i - 1] + nums[i] : nums[i];
                oddSum[i] = i > 0 ? oddSum[i - 1] : 0;
            }
            else {
                oddSum[i] = oddSum[i - 1] + nums[i];
                evenSum[i] = evenSum[i - 1];
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i++){
            

            if(i % 2  == 0){
                int es = evenSum[i] + oddSum[n - 1] - oddSum[i] - nums[i];
                int os = oddSum[i] + evenSum[n - 1] - evenSum[i];

                if(es == os)
                    ret++;
            }
            else{
                int es = evenSum[i] + oddSum[n - 1] - oddSum[i];
                int os = oddSum[i] + evenSum[n - 1] - evenSum[i] - nums[i];

                if(es == os)
                    ret++;
            }
        }

        return ret;
    }
};

int main(){

    vector<int> nums = {1,2,3};
    Solution sol;
    cout << sol.waysToMakeFair(nums);
}