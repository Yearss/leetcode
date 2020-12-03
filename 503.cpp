
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ret(n);
        stack<int> st;
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            st.push(nums[i]);
        }
        
        for(int i = n - 1; i >= 0 ; i--){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            if(st.empty())
                ret[i] = -1;
            else
                ret[i] = st.top();
            st.push(nums[i]);
        }

        return ret;
    }   
};

int main(){


    vector<int> nums = {1,2,1};
    Solution sol;
    auto ret = sol.nextGreaterElements(nums);
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << ' ';
}