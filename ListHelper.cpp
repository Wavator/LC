//
// Created by Zhao on 2020/8/2.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generate(vector<int> x) {
    auto hd = new ListNode(x[0]);
    auto curr = hd;
    for (int i = 1; i < x.size(); ++i) {
        curr->next = new ListNode(x[i]);
        curr = curr->next;
    }
    return hd;
}

void print_list(ListNode* x, ListNode *y = NULL, bool printy = false) {
    cout << "------------------------------\n";
    while (x != y) {
        cout << x->val << ' ';
        x = x->next;
    }
    if (printy) {
        cout << y->val << ' ';
    }
    cout << "\n------------------------------\n";
}
