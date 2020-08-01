//
// Created by Zhao on 2020/8/1.
//

class Solution {
public:

    struct TrieNode {
        TrieNode * son[2];
    } * root;

    TrieNode * add(TrieNode* x, char c) {
        if (x->son[c - '0']) {
            return x->son[c - '0'];
        }
        return x->son[c - '0'] = new TrieNode();
    }

    int search_max(const string &val, TrieNode * x) {
        string mx = "";
        for (const auto &c: val) {
            int now = c == '0'? 1: 0;
            if (x->son[now]) {
                mx.push_back('1');
                x = x->son[now];
            } else {
                mx.push_back('0');
                x = x->son[!now];
            }
        }
        int ans = 0;
        reverse(mx.begin(), mx.end());
        for (int i = 0; i < mx.size(); ++i) {
            if (mx[i] == '1') {
                ans |= (1 << i);
            }
        }
        return ans;
    }

    void insert(const string &s, TrieNode* &root) {
        TrieNode * curr = root;
        for (auto c: s) {
            int now = c - '0';
            if (curr->son[now]) {
                curr = curr->son[now];
            } else {
                curr->son[now] = new TrieNode();
                curr = curr->son[now];
            }
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int mx = *max_element(nums.begin(), nums.end()), length = 1;
        if (mx) {
            while (mx >>= 1) ++length;
        }
        vector<string> num_string;
        for (auto &item: nums) {
            num_string.emplace_back();
            while (item) {
                num_string.back().push_back('0' + (item & 1));
                item >>= 1;
            }
            while (num_string.back().length() < length) {
                num_string.back().push_back('0');
            }
            reverse(num_string.back().begin(), num_string.back().end());
        }
        int ans = 0;
        for (auto&s: num_string) {
            insert(s, root);
            ans = max(ans, search_max(s, root));
        }
        return ans;
    }
};

/*
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.

 使用trie树，新数字进来就是trie树的增加和查询操作。时间复杂度O(32*N)，空间复杂度O(32*N)
 注意查询的正确性是通过异或的交换律保证的。
 若最大异或值是由a^b得到，则无论先放入a，查询b，还是先放入b，查询a，都会得到这个最大异或值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */