//
// Created by Zhao on 2020/7/27.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    string longestPalindrome(string s) {
        int mx = 0, fl = 0, fr = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i;
            while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            if (mx < r - l + 1) {
                mx = r - l + 1;
                fl = l;
                fr = r;
            }
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                l = i, r = i + 1;
                while (l > 0 && r + 1 < s.size() && s[l - 1] == s[r + 1]) {
                    l--;
                    r++;
                }
                if (mx < r - l + 1) {
                    mx = r - l + 1;
                    fl = l;
                    fr = r;
                }
            }
        }
        return s.substr(fl, fr - fl + 1);
    }
};

//int main() {
//    cout << s.longestPalindrome("cbbd") << endl;
//    cout << s.longestPalindrome("aaa") << endl;
//    return 0;
//}

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 有很多做法，最快的是马拉车算法（Manacher's algorithm）,时间空间都是O(n),不做竞赛应该不需要了解,
 有兴趣可以去我的acm_template：github.com/Wavator/ACM_template/blob/master/string/manacher.cpp 里看看是怎么做的
 这里写的是除了最优解之外复杂度最低O(n^2)且最节省空间O(1)的算法——中心拓展，就是枚举中心向两边拓展
 还有一种做法就是dp，时间也是n^2但是空间还是n^2，不如中心拓展，方程是
 初始化:
 dp[i][i] = true for i from 1 to n
 dp[i][i + 1] = true if s[i] == s[i + 1] for i from 1 to n - 1
 转移：
 dp[i][j] = i < j && dp[i + 1][j - 1] && s[i + 1] == s[j - 1]
 最后输出最长的满足dp[i][j]=true的ij之间的子串即可

 * */