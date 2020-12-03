
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct ListNode{
    ListNode* next;
    int val;
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;

        while(head){
            st.push(head->val);
            head = head->next;
        }

        stack<int> st1;
        vector<int> ret;
        while(!st.empty()){

            int x = st.top();
            st.pop();

            while(!st1.empty() && st1.top() <= x){
                st1.pop();
            }
            if(st1.empty())
                ret.push_back(0);
            else
                ret.push_back(st1.top());
            st1.push(x);
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};