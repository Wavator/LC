//
// Created by Zhao on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26, 0);
        for (char &c: S) {
            cnt[c - 'a']++;
        }
        int gr = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        int max_cnt = cnt[gr];
        sort(cnt.rbegin(), cnt.rend());
        if (cnt[0] > (S.length() + 1) / 2) {
            return "";
        }
        fill(cnt.begin(), cnt.end(), 0);
        for (char &c: S) {
            cnt[c - 'a']++;
        }
        string ans = "";
        while (max_cnt) {
            ans += ('a' + gr);
            bool ok = false;
            for (int i = 0; i < 26; ++i) {
                if (!ok && cnt[i] && i != gr) {
                    ok = true;
                    cnt[i]--;
                    ans += ('a' + i);
                }
                else if (cnt[i] && cnt[i] >= max_cnt - 1 && i != gr) {
                    cnt[i]--;
                    ans += ('a' + i);
                }
            }
            max_cnt--;
        }
        return ans;
    }
}s;
//
//int main() {
//    cout << s.reorganizeString("vvvlo") << endl;
//    cout << s.reorganizeString("aabbcc") << endl;
//    cout << s.reorganizeString("aabc") << endl;
//    cout << s.reorganizeString("aaabbbcccddd") << endl;
//    return 0;
//}

/*
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

 随意排列，构造一种排序规则即可，注意写代码不要写出一堆bug。
 我的构造方式是sort字符串，取最多出现的字符X，形式上因为可能是奇数，所以把X放在每一节的开头（这样最后还可以放一个X）
 也就是X...X...X...X...的形式，除了最后一个...之外其他...都必须存在数字
 这样记录每个数字的cnt，在每一轮，判断这一轮需要哪些字母，如果该字母的当前cnt大于剩余轮数，则必须要在此轮使用（实际上可以不用但是写起来非常麻烦）
 具体代码上图
 * */

