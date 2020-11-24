

#include <vector>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        auto head = new ListNode(0);

        auto t = pHead;
        while(t){
            auto next = t -> next;
            t->next = head->next;
            head->next = t;
            t = next;
        }

        return head->next;

    }
};