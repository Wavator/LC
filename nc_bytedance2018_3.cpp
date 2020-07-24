//
// Created by Zhao on 2020/7/24.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int m;
    cin >> s >> m;
    vector<vector<int> > pos(26);
    for (int i = 0; i < s.length(); ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    int ans = 1;
    for (int C = 0; C < 26; ++C) {
        char now = 'a' + C;
        int n = count(s.begin(), s.end(), now);
        if (n <= 1) {
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n; ++i) {
            dp[i - 1][i] = pos[C][i] - pos[C][i - 1] - 1;
        }

        for (int j = 2; j < n; ++j) {
            for (int i = 0; i + j < n; ++i) {
                dp[i][i + j] = dp[i + 1][i + j - 1] + (pos[C][i + j] - pos[C][i]) - j;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (dp[i][j] <= m) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
    }
    cout << ans << endl;
}

//int main() {
//    solve();
//    return 0;
//}

/*
字符串S由小写字母构成，长度为n。定义一种操作，每次都可以挑选字符串中任意的两个相邻字母进行交换。询问在至多交换m次之后，字符串中最多有多少个连续的位置上的字母相同？

输入描述:
第一行为一个字符串S与一个非负整数m。(1 <= |S| <= 1000, 1 <= m <= 1000000)

输出描述:
一个非负整数，表示操作之后，连续最长的相同字母数量。

输入例子1:
abcbaa 2

输出例子1:
2

例子说明1:
使2个字母a连续出现，至少需要3次操作。即把第1个位置上的a移动到第4个位置。
所以在至多操作2次的情况下，最多只能使2个b或2个a连续出现。


 dp[i][j]，i-j个完全连在一起需要多少操作，考虑从i+1,j-1转移。
 pos数组代表位置
 dp[i][i + j] = dp[i + 1][i + j - 1] + (pos[C][i + j] - pos[C][i]) - j;
 复杂度O(26*|S|^2)

 * */

