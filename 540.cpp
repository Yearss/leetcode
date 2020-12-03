
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int s = 0, e = nums.size() - 1;
        while(s < e){
            int m = (s + e) / 2;
            
            if(nums[m] == nums[m + 1]){
                if((e - m - 1) % 2 != 0){
                    s = m + 2;
                }
                else{
                    e = m - 1;
                }
            }
            else{
                if((e - m) % 2 != 0){
                    s = m + 1;
                }
                else
                    e = m;
            }
        }

        return s;
    }
};

int main(){


    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    Solution sol;
    cout << sol.singleNonDuplicate(nums);
}