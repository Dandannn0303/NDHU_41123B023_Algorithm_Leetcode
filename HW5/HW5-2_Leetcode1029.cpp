#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
     {
        int n = costs.size()/2;
        //true, a 比較優先 false, b 比較優先
        sort(costs.begin(),costs.end(),cmp);
        int total=0;
        // 前 n 個 → 去 B（最適合去 B）
        for(int i=0;i<n;i++)
        {
            total+=costs[i][1];
        }
         // 後 n 個 → 去 A（比較適合去 A）
        for(int i = n;i<2*n;i++)
        {
            total+=costs[i][0];
        }
        return total;
    }
    static bool cmp(vector<int>&a , vector<int>&b )
        {
            //比較兩個人：誰去B比較划算
            //true, a 比較優先 false, b 比較優先
            //a[0] 是 a 去 A 的成本
            //a[1] 是 a 去 B 的成本
            //b[0] 是 b 去 A 的成本
            //b[1] 是 b 去 B 的成本
            //回傳 a < b 告訴 sort 我要由小到大排（升序）。
            return ((a[1]-a[0])<(b[1]-b[0]));
        }
};