
#include <vector>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int ret = 0;
        int k = 0;
        for(int i = 0, j = 0; i < N; i++){
            while(j < N && k < 2){
                if(nums[j] == 0){
                    k++;
                }
                j++;
            }
            if(j == N && k > 0){
                ret = max(ret, j - i - k);
            }
            else if(j == N){
                ret = max(ret, j - i - 1);    
            }
            else{
                ret = max(ret, j - i - 2);
            }

            if(nums[i] == 0)
                k--;
        }

        return ret;
    }
};