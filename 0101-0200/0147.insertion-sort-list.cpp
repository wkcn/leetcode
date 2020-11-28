#include "common.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next) {
            // p 已经排好序
            ListNode *r = p->next;
            // cout << "select: " << r->val << endl;
            p->next = r->next; // 将r取出来
            // PRINT_LIST(dummy.next);
            // 因为r可能会插入到old p的后面, 所以先更新p
            ListNode *u = &dummy;
            // 如果r->val大于已经排好序列的末尾元素, 可以直接插入, 就不用遍历一遍了
            while (u != p && u->next->val < r->val) {
                u = u->next;
            }
            // cout << "insert after: " << u->val << endl;
            if (u == p) p = r;
            r->next = u->next;
            u->next = r;
            // cout << "update" << endl;
            // PRINT_LIST(dummy.next);
            // cout << "p is " << p->val << endl;
        }
        return dummy.next;
    }
};

int main() {
  ListNode *head = INPUT_LIST<ListNode>();
  PRINT_LIST(Solution().insertionSortList(head));
  return 0;
}
