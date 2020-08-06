//
// Created by Zhao on 2020/8/6.
//

class Solution {
public:
    static const int N = 1005;
    int fa[N];

    int find(int x) {
        return x == fa[x]? x: fa[x] = find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) {
            return false;
        }
        fa[x] = y;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < N; ++i) fa[i] = i;
        for (auto&e: edges) {
            if (!merge(e[0], e[1])) {
                return e;
            }
        }
        assert(false);
        return vector<int>{};
    }
};
//
//int main() {
//    vector<vector<int>> test = {
//            {1, 2},
//            {1, 3},
//            {2, 3}
//    };
//    auto ans(s.findRedundantConnection(test));
//    cout << ans[0] << ' ' << ans[1] << endl;
//    return 0;
//}
/*
 在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
并查集，发现不需要合并的边就结束
 * */