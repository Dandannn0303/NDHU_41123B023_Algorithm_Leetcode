#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    // 一般線性 House Robber
    int robRange(vector<int>& nums, int start, int end) {

        // prev1 = dp[i-1]
        int prev1 = 0;

        // prev2 = dp[i-2]
        int prev2 = 0;

        // 從 start 走到 end
        for (int i = start; i <= end; i++) {

            // 不偷目前房子 vs 偷目前房子
            int current = max(prev1, prev2 + nums[i]);

            // 更新 dp 狀態
            prev2 = prev1;
            prev1 = current;
        }

        // 回傳最大金額
        return prev1;
    }

    int rob(vector<int>& nums) {

        // 只有一間房子
        // 直接偷
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();

        // 情況 1：
        // 偷 0 ~ n-2
        int case1 = robRange(nums, 0, n - 2);

        // 情況 2：
        // 偷 1 ~ n-1
        int case2 = robRange(nums, 1, n - 1);

        // 回傳兩種情況最大值
        return max(case1, case2);
    }
};