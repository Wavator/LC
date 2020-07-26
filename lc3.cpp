//
// Created by Zhao on 2020/7/26.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0, r = 0;
        vector<bool> contains(128, false);
        while (r < s.size()) {
            if (!contains[s[r]]) {
                contains[s[r]] = true;
            } else {
                while (s[l] != s[r]) {
                    contains[s[l++]] = false;
                }
                l++;
            }
            ans = max(ans, ++r - l);
        }
        return ans;
    }
};

//int main() {
//    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
//    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
//    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
//    return 0;
//}

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 这个题没有数据范围，找个On的算法做，bool数组维护是否出现过，左右指针表示符合唯一性的左右界，不断把r++（相当于枚举右界），然后用维护的bool数组
 更新l同时更新bool数组。

 * */
