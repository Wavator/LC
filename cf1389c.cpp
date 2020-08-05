//
// Created by Zhao on 2020/8/5.
//

class solution {
    int getMiniDel(string &s) {
        int n = s.size();
        int ans = n;
        //solve one, t=xxxxxxxxxx
        for (char i = '0'; i <= '9'; ++i) {
            int curr = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j] != i) {
                    ++curr;
                }
            }
            if (ans > curr) {
                ans = curr;
            }
        }
        //solve two, t=xyxyxyxyxyxyxyxyxy
        for (char i = '0'; i <= '9'; ++i) {
            for (char j = '0'; j <= '9'; ++j) {
                if (i == j) {
                    continue;
                }
                int curr = 0;
                int remains = 0;
                for (int k = 0; k < n; ++k) {
                    if (remains & 1) {
                        if (s[k] == j) {
                            ++remains;
                        } else {
                            ++curr;
                        }
                    } else {
                        if (s[k] == i) {
                            ++remains;
                        } else {
                            ++curr;
                        }
                    }
                }
                if (remains & 1) {
                    ++curr;
                }
                if (curr < ans) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};

/*
Let's call left cyclic shift of some string t1t2t3…tn−1tn as string t2t3…tn−1tnt1.

Analogically, let's call right cyclic shift of string t as string tnt1t2t3…tn−1.

Let's say string t is good if its left cyclic shift is equal to its right cyclic shift.

You are given string s which consists of digits 0–9.
2≤|s|≤2⋅10^5

 简单来说就是找到最长的一个子序列，使得这个子序列满足：左移一位并把最左的字符补到最右==右移一位并把最右的字符补到最左
输入：
3
95831
100120013
252525252525
 输出：
3
5
0
做法是观察子串tnt1t2t3…tn−1和t2t3…tn−1tnt1，可知t2=tn,t1=t2......最后推出t1=t3=t5...,t2=t6=t8...
 也就是循环节只能是2（或者1），枚举循环节是哪两个数字即可，复杂度O(10*10*|s|)
 * */