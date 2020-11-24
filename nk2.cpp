
#include <vector>
#include <iostream>


using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // 快指针
        auto p = head;
        // 慢指针
        auto q = head;

        while(p){
            p = p->next;
            if(p == nullptr)
                return false;
            p = p->next;
            q = q->next;
            if(p == q)
                return true;
        }

        return false;
        
    }
};