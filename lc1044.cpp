//
// Created by Zhao on 2020/7/27.
//

#include <bits/stdc++.h>
using namespace std;
/*稍微超时，原因应该是字符串的substr操作不是O1进行的，哈希操作也无法O1，这个超时启发了正确算法
//    string longestDupSubstring(string S) {
//        int l = 0, r = S.size() - 1;
//        string ans = "";
//        while (r >= l) {
//            int mid = (l + r) / 2;
//            unordered_set<string> st;
//            bool f = false;
//            for (int i = 0; i + mid <= S.size(); ++i) {
//                if (!st.insert(S.substr(i, mid)).second) {
//                    ans = S.substr(i, mid);
//                    f = true;
//                    break;
//                }
//            }
//            if (f) {
//                l = mid + 1;
//            } else {
//                r = mid - 1;
//            }
//        }
//        return ans;
//    }
 * */
class Solution {
public:
    const int mod = 1000000007;
    const int mult = 29;//29>=26 and 29 is a prime number

    inline int mul(int a, int b) {
        long long res = (long long) a * b % mod;
        return (int) res;
    }

    inline int add(int a, int b) {
        a += b;
        return a < mod? a: a - mod;
    }

    inline int sub(int a, int b) {
        a -= b;
        return a < 0? a + mod: a;
    }

    int inv(int a) {
        a %= mod;
        if (a < 0) a += mod;
        int b = mod, u = 0, v = 1;
        for (; a;) {
            int t = b / a;
            b -= t * a;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (b != 1)
            return -1;
        if (u < 0) u += mod;
        return u;
    }
    string longestDupSubstring(string S) {
        int l = 1, r = S.size() - 1;
        string ans = "";
        vector<int> mult_pows(S.size(), 1);
        for (int i = 1; i < (int)mult_pows.size(); ++i) {
            mult_pows[i] = mul(mult_pows[i - 1], mult);
        }
        //for(int&x:mult_pows)cerr<<x<<' ';cerr<<endl;
        int div = inv(mult);
        while (r >= l) {
            int mid = (l + r) / 2;
            //cerr << mid << endl;
            bool f = false;
            unordered_set<int> st;
            int hashval = 0;
            for (int i = 0; i < mid; ++i) {
                hashval = add(hashval, mul(S[i] - 'a', mult_pows[i]));
            }
            st.insert(hashval);
            for (int i = 1; i + mid - 1 < S.size(); ++i) {
                hashval = sub(hashval, S[i - 1] - 'a');
                hashval = mul(hashval, div);
                hashval = add(hashval, mul(S[i + mid - 1] - 'a', mult_pows[mid - 1]) );
                if (!st.insert(hashval).second) {
                    ans = S.substr(i, mid);
                    f = true;
                    break;
                }
            }
            //cerr << f << endl;
            if (f) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
//
//int main() {
//    cout << s.longestDupSubstring("banana") << endl;
//    cout << s.longestDupSubstring("abcd") << endl;
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

 hash = sigma((s[i]-'a') * pow(29,i))
 递推O1求得新hash值

 * */