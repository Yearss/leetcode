
#include <vector>
#include <iostream>
#include <unordered_set>

struct ListNode{
    ListNode* next;
    int val;
};

using namespace std;


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        int ret = 0, tmp = 0;
        unordered_set<int> us;
        for(int i = 0; i < G.size(); i++)
            us.insert(G[i]);

        ListNode* cur = head;
        while(cur){
            if(us.count(cur->val)){
                tmp++;
            }
            else if(tmp > 0){
                ret++;
                tmp = 0;
            }
            else
                tmp = 0;
            cur = cur->next;
        }

        if(tmp > 0){
            ret++;
        }
        return ret;

    }
};

int main(){

}