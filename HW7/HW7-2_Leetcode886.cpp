#include <vector>              // 引入 vector 容器
#include <queue>               // 引入 queue（BFS 用）
using namespace std;           // 使用標準命名空間

class Solution {               // 定義解題類別（LeetCode 標準格式）
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {  // 主函式

        vector<vector<int>> graph(n + 1);  // 建立鄰接表（1 ~ n，所以開 n+1）

        for (auto& d : dislikes) {        // 遍歷每一對互相討厭的人
            int a = d[0], b = d[1];       // 取出兩個人
            graph[a].push_back(b);        // a 討厭 b（建立邊）
            graph[b].push_back(a);        // b 討厭 a（雙向圖）
        }

        vector<int> color(n + 1, 0);      // 顏色陣列：0=未染色，1=-1=兩個不同群

        for (int i = 1; i <= n; i++) {    // 因為圖可能不連通，要每個點都檢查

            if (color[i] != 0) continue;  // 如果已經染色過就跳過

            queue<int> q;                // BFS 佇列
            q.push(i);                   // 把起點加入
            color[i] = 1;                // 隨便先染成 1

            while (!q.empty()) {        // BFS 開始

                int node = q.front();   // 取出目前節點
                q.pop();                // 移除隊首

                for (int nei : graph[node]) {  // 看所有鄰居

                    if (color[nei] == 0) {     // 如果還沒染色
                        color[nei] = -color[node]; // 染成相反顏色（分不同組）
                        q.push(nei);            // 加入 BFS
                    }

                    else if (color[nei] == color[node]) { // 如果鄰居顏色相同
                        return false;          // 代表不能分兩組（衝突）
                    }
                }
            }
        }

        return true;   // 全部都沒衝突 => 可以二分
    }
};