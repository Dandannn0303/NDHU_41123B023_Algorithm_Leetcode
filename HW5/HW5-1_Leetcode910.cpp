#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
解題想法：
先想「最大值可能在哪？
左邊（+k 後的最大）
nums[i] + k
右邊（-k 後的最大）
nums[n - 1] - k
再想「最小值可能在哪？」
左邊（+k 後的最小）
nums[0] + k
右邊（-k 後的最小）
nums[i + 1] - k
1. 先排序 nums
2. 每個數只能 +k 或 -k
3. 想成：前面一段 +k，後面一段 -k
4. 枚舉分界點 i，算每種可能的最大最小差
5. 取最小的答案

*/
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //初始 ans
        int ans = nums[n - 1] - nums[0];

        for (int i = 0; i < n - 1; i++) {
            int high = max(nums[i] + k, nums[n - 1] - k);
            int low  = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, high - low);//目前的ans跟high-low比較
        }

        return ans;
    }
};