//
// Created by Zhao on 2020/7/28.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int k, ans;

    vector<vector<bool>> vis;

    int dgt(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    void dfs(int r, int c, int mx_r, int mx_c) {
        if (r < 0 || c < 0 || r >= mx_r || c >= mx_c || vis[r][c]) {
            return;
        }
        vis[r][c] = true;
        if (dgt(r) + dgt(c) > k) {
            return;
        }
        //cerr << r << ' ' << c << endl;
        ans++;
        dfs(r + 1, c, mx_r, mx_c);
        dfs(r, c + 1, mx_r, mx_c);
        dfs(r - 1, c, mx_r, mx_c);
        dfs(r, c - 1, mx_r, mx_c);
    }

    int movingCount(int threshold, int rows, int cols)
    {
        k = threshold;
        ans = 0;
        vis = vector<vector<bool>>(rows, vector<bool>(cols, false));
        dfs(0, 0, rows, cols);
        return ans;
    }
};
//
//int main() {
//    cout << s.movingCount(5, 10, 10) << endl;
//    return 0;
//}

/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

 dfs模拟

