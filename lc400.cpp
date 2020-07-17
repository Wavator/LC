//
// Created by Zhao on 2020/7/18.
//

class Solution {
public:
    int findNthDigit(int n) {
        int pw = 0;
        while (n > (pw + 1) * 9 * pow(10, pw)) {
            n -= (pw + 1) * 9 * pow(10, pw);
            ++pw;
        }
        int kk = pow(10, pw);
        int len = to_string(kk).size();
        while (n > len) {
            n -= len;
            kk++;
        }
        return to_string(kk)[n - 1] - '0';
    }
};

/*
在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

注意:
n 是正数且在32位整数范围内 ( n < 231)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nth-digit
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 解题思路，9+90+900+9000这样随便模拟一下，因为是调和级数，所以最后n -= len不会执行很多步
 */
