//
// Created by Zhao on 2020/8/12.
//

class Solution {
public:
    static const int MAXN = 10002;
    int fa[MAXN];

    int find(int x) {
        return x == fa[x]? x: fa[x] = find(fa[x]);
    }

    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        fa[a] = b;
        return true;
    }

    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [&](const vector<int>&a, const vector<int>&b) {
            return a[2] < b[2];
        });
        for (int i = 1; i <= N; ++i) {
            fa[i] = i;
        }
        int ans = 0;
        for (auto &edge: connections) {
            if (merge(edge[0], edge[1])) {
                ans += edge[2];
                --N;
            }
        }
        return N == 1? ans: -1;
    }
};
