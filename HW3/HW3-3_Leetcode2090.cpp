#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        // 建立用來存放答案的陣列 avgs，長度與 nums 相同。
        // 【關鍵技巧】：直接將所有元素預設為 -1。這樣陣列頭尾那些「湊不滿左右各 k 個」的位置，
        // 就不需要我們再額外寫判斷式去填補 -1 了。
        vector<int> avgs(n,-1);

        long long sum = 0;//總和

        // 計算一個完整的視窗總共需要幾個元素 (左邊 k 個 + 中心 1 個 + 右邊 k 個)
        int windowSize=2*k+1;

        if (windowSize>n)
        return avgs;

        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];

            // 判斷目前的 i 是否已經走到了至少 2*k 的位置。
            // 因為索引從 0 開始，當 i == 2*k 時，
            // 代表我們剛好收集滿了windowSize (也就是 2k+1) 個元素。
            if(i>=2*k){

                // 步驟 2：計算平均值並寫入答案。
                // 既然視窗滿了，我們要算的是「視窗正中心」的平均值。
                // 目前視窗最右邊在 i，那麼正中心的位置剛好就是往左退 k 步，也就是 i - k。
            avgs[i-k]=sum/windowSize;

            // 步驟 3：滑動窗口！(這步是效能高的關鍵)
                // 為了讓下一次迴圈能把右邊下一個新元素加進來，而且保持視窗大小不變，
                // 我們必須把當前視窗「最左邊」的那個舊元素從總和裡扣掉。
                // 視窗最右邊是 i，最左邊的位置就是 i 往前推 2k，也就是 i - 2 * k。
            sum=sum-nums[i-2*k];
            }
        }
        return avgs;
    }
};