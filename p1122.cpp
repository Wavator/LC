#include <bits/stdc++.h>
using namespace std;
const int N = 16000 + 5;
int beauty[N];
vector<int> g[N];

int ans = INT_MIN;

int dfs(int u, int fa) {
    int curr = beauty[u];
    for (int v: g[u]) {
        if (v != fa) {
            curr += dfs(v, u);
        }
    }
    if (curr > ans) {
        ans = curr;
    }
    return curr > 0? curr: 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &beauty[i]);
    }
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}

