//
// Created by Zhao on 2020/8/6.
//

class Solution {
public:
    static const int N = 1005;
    int fa[N], in_degree[N];

    int find(int x) {
        return x == fa[x]? x: fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        fa[x] = y;
        return true;
    }

    bool check(const vector<int>&forbid, const vector<vector<int>> &edges) {
        for (int i = 0; i < N; ++i) fa[i] = i;
        for (const auto&e: edges) {
            if (e != forbid && !merge(e[0], e[1])) {
                return false;
            }
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int tp = -1;
        for (auto &e: edges) {
            if (in_degree[e[1]]) {
                tp = e[1];
            }
            in_degree[e[1]] = 1;
        }
        cerr << tp << endl;
        if (~tp) {
            vector<vector<int>> possible;
            for (auto &e: edges) {
                if (e[1] == tp) {
                    possible.push_back(e);
                }
            }
            return check(possible[1], edges)? possible[1]: possible[0];
        } else {
            for (int i = 0; i < N; ++i) fa[i] = i;
            for (auto &e: edges) {
                if (!merge(e[0], e[1])) {
                    return e;
                }
            }
            assert(false);
            return vector<int>{};
        }
    }
};

/*
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1:

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的有向图如下:
  1
 / \
v   v
2-->3
示例 2:

输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
输出: [4,1]
解释: 给定的有向图如下:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
注意:

二维数组大小的在3到1000范围内。
二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 实际上有两种情况，这个树本来是个链，加了一条边成环，这种情况下所有点的入度都是1，否则树上加一条有向边会出现且仅出现一个入度为2的点
 找出以该点为终点的两条边，分别用并查集判断是不是一棵树即可
 * */