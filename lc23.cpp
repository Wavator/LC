//
// Created by Zhao on 2020/8/3.
//

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int, int> > st;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]!= NULL) {
                st.emplace(lists[i]->val, i);
                lists[i] = lists[i]->next;
            }
        }
        auto res = new ListNode(0), curr = res;
        while (!st.empty()) {
            auto now = *st.begin();
            st.erase(st.begin());
            curr->next = new ListNode(now.first);
            curr = curr->next;
            if (lists[now.second] != NULL) {
                st.emplace(lists[now.second]->val, now.second);
                lists[now.second] = lists[now.second]->next;
            }
        }
        return res->next;
    }
}s;

/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */