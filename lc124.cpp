//
// Created by Zhao on 2020/7/26.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = -2147483648;

    int dfs(TreeNode* rt) {
        if (rt == NULL) {
            return 0;
        }
        int dl = dfs(rt->left), dr = dfs(rt->right);
        if (dl < 0) {
            dl = 0;
        }
        if (dr < 0) {
            dr = 0;
        }
        ans = max(ans, dl + dr + rt->val);
        return rt->val + max(dl, dr);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

/*
 * 给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 dfs，dfs返回过当前节点的最优解。如果左子树最优解或右子树最优解小于0，直接当没这孩子就可以，否则会让结果变小。
 * */
