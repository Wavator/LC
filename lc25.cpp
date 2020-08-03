//
// Created by Zhao on 2020/8/4.
//

class Solution {
public:

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        auto pre = tail->next, curr = head;
        while (pre != tail) {
            auto curr_next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = curr_next;
        }
        return make_pair(tail, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        for (auto curr = head; curr != NULL; curr = curr->next) {
            ++length;
        }
        int revRound = length / k;
        auto res = new ListNode(0);
        auto curr = res;
        res->next = head;
        for (int i = 0; i < revRound; ++i) {
            auto tail = curr;
            for (int j = 0; j < k; ++j) {
                tail = tail->next;
            }
            auto temp_next = tail->next;
            //print_list(curr->next, tail, true);
            auto rev = reverse(curr->next, tail);
            //print_list(rev.first, rev.second, true);
            curr->next = rev.first;
            rev.second->next = temp_next;
            curr = rev.second;
        }
        return res->next;
    }
};
/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
