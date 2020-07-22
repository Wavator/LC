#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int> satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int curr_sum = 0, ans = 0;
        for (auto x: satisfaction) {
            if (curr_sum + x > 0) {
                curr_sum += x;
                ans += curr_sum;
            }
        }
        return ans;
    }
}s;

//int main() {
//    cout << s.maxSatisfaction(vector<int>{-1,-8,0,5,-9}) << endl;
//    cout << s.maxSatisfaction(vector<int>{4,3,2}) << endl;
//    cout << s.maxSatisfaction(vector<int>{-1,-4,-5}) << endl;
//    cout << s.maxSatisfaction(vector<int>{-2,5,-1,0,3,-3}) << endl;
//    //cout << s.maxSatisfaction(vector<int>{-1,-8,0,5,-9}) << endl;
//    return 0;
//}

/*
一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。

一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是 time[i]*satisfaction[i] 。

请你返回做完所有菜 「喜爱时间」总和的最大值为多少。

你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reducing-dishes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 排序是必然的，因为越大的数乘越大的系数收益越大，越小的数乘越小的系数收益越小（负数一样）
 标题是dp结果dp超时。。。
 贪心就是排序之后如果加入这道菜有正收益就做，注意，0不做，如果0做，负数的总体id会变大
 * */
