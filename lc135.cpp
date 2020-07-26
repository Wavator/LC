//
// Created by Zhao on 2020/7/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<int> &ans, const vector<pair<int,int>>&g, int i, int depth = 1) {
        if (i == -1) {
            return;
        }
        if (ans[i] < depth) {
            ans[i] = depth;
        }
        if (g[i].first == -1 && g[i].second == -1) {
            return;
        }
        dfs(ans, g, g[i].first, depth + 1);
        dfs(ans, g, g[i].second, depth + 1);
    }

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int> > g(n, {-1, -1});
        vector<bool> is_root(n, true);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] < ratings[i - 1]) {
                g[i].first = i - 1;
                is_root[i - 1] = false;
            }
            if (i + 1 < n && ratings[i] < ratings[i + 1]) {
                g[i].second = i + 1;
                is_root[i + 1] = false;
            }
        }
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            if (is_root[i]) {
                dfs(ans, g, i);
            }
        }
        int res = 0;
        for (int x: ans) {
            res += x;
        }
        return res;
    }
};

//int main() {
//    vector<int> test1 = {1, 0, 2};
//    cout << s.candy(test1) << endl;
//    test1 = {1,6,10,8,7,3,2};
//    cout << s.candy(test1) << endl;
//    test1 = {1,3,2,2,1};
//    cout << s.candy(test1) << endl;
//    return 0;
//}

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 乍一看分类讨论，实际上很明显是有向图跑个depth的问题，这里可以看成n个DAG，从N个DAG中找到所有没有入度的点（最小点）做dfs，
 在这个过程中，更新每个点的糖果数（dfs的depth），如果之前有被dfs过，而且这一轮又dfs到了这个点，那么取最大（倒过来看左右都要满足要求）

 * */