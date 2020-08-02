//
// Created by Zhao on 2020/8/2.
//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto hd = new ListNode(0), curr = hd;
        while (l1 != NULL || l2 != NULL) {
            int now_value;
            if (l1 == NULL) {
                now_value = l2->val + carry;
                l2 = l2->next;
            } else if (l2 == NULL) {
                now_value = l1->val + carry;
                l1 = l1->next;
            } else {
                now_value = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            curr->next = new ListNode(now_value % 10);
            curr = curr->next;
            carry = now_value > 9? 1: 0;
        }
        if (carry) {
            curr->next = new ListNode(1);
        }
        return hd->next;
    }
};