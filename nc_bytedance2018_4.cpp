//
// Created by Zhao on 2020/7/25.
//

#include <bits/stdc++.h>
using namespace std;

int calculate(char c, const string &s, int m) {
    vector<int> pos;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            pos.push_back(i);
        }
    }
    if (pos.size() > m ) {
        pos.push_back(s.size());
        int ans = 0;
        for (int i = 0; i + m + 1< pos.size(); ++i) {
            ans = max(ans, pos[i + m + 1] - pos[i] - 1);
        }
        return ans;
    }
    return s.size();
}

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    cout << max(calculate('a', s, m), calculate('b', s, m)) << endl;
}

//int main() {
//    solve();
//    return 0;
//}

/*
有一个仅包含’a’和’b’两种字符的字符串s，长度为n，每次操作可以把一个字符做一次转换（把一个’a’设置为’b’，或者把一个’b’置成’a’)；但是操作的次数有上限m，问在有限的操作数范围内，能够得到最大连续的相同字符的子串的长度是多少。

输入描述:
第一行两个整数 n , m (1<=m<=n<=50000)，第二行为长度为n且只包含’a’和’b’的字符串s。

输出描述:
输出在操作次数不超过 m 的情况下，能够得到的 最大连续 全’a’子串或全’b’子串的长度。

输入例子1:
8 1
aabaabaa

输出例子1:
5

例子说明1:
把第一个 'b' 或者第二个 'b' 置成 'a'，可得到长度为 5 的全 'a' 子串。

 分别比较m次操作全是把a换成b或是把b换成a得到的最长连续串
 比如求a，就是相隔m+1个的b的字符位置差-1

 * */
