//
// Created by Zhao on 2020/8/13.
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> tmp[3];
        for (int i = 0; i < nums.size(); ++i) {
            tmp[i % 3].push_back(nums[i]);
        }
        for (auto&x: tmp) {
            x.resize(unique(x.begin(), x.end()) - x.begin());
        }
        nums.clear();
        for (const auto&x: tmp) {
            nums.insert(nums.end(), x.begin(), x.end());
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int aim = -(nums[i] + nums[j]);
                int l = j + 1, r = nums.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] == aim) {
                        res.push_back({nums[i], nums[j], nums[mid]});
                        break;
                    }
                    if (nums[mid] < aim) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());
        return res;
    }
};
