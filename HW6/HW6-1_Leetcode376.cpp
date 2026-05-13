#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:

    // 回傳最長 wiggle subsequence 的長度
    int wiggleMaxLength(vector<int>& nums) {

        // 如果陣列長度小於 2
        // 代表只有 0 或 1 個元素
        // 直接回傳長度即可
        if (nums.size() < 2) {
            return nums.size();
        }

        // 計算前兩個元素的差值
        int prevDiff = nums[1] - nums[0];

        // 如果前兩個數字不同
        // 那目前長度至少是 2
        // 否則只有 1
        int count = (prevDiff != 0) ? 2 : 1;

        // 從第 3 個元素開始遍歷
        for (int i = 2; i < nums.size(); i++) {

            // 計算目前相鄰元素的差值
            int diff = nums[i] - nums[i - 1];

            // 情況 1：
            // 現在是上升(diff > 0)
            // 而前一次是下降或持平(prevDiff <= 0)
            //
            // 情況 2：
            // 現在是下降(diff < 0)
            // 而前一次是上升或持平(prevDiff >= 0)
            //
            // 代表發生 wiggle
            if ((diff > 0 && prevDiff <= 0) ||
                (diff < 0 && prevDiff >= 0)) {

                // wiggle 長度 +1
                count++;

                // 更新前一次差值方向
                prevDiff = diff;
            }
        }

        // 回傳答案
        return count;
    }
};