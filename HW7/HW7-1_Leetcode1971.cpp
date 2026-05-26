#include <vector>              // 引入 vector 容器
#include <queue>               // 引入 queue（BFS 用）
using namespace std;           // 使用標準命名空間

class Solution {               // LeetCode 標準類別
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { // 主函式

        vector<vector<int>> graph(n);     // 建立鄰接表，大小為 n（0 ~ n-1）

        for (auto& e : edges) {          // 遍歷所有邊
            int u = e[0];                // 取出起點
            int v = e[1];                // 取出終點
            graph[u].push_back(v);       // 加入 u -> v
            graph[v].push_back(u);       // 加入 v -> u（雙向圖）
        }

        vector<bool> visited(n, false);  // 記錄每個節點是否拜訪過

        queue<int> q;                    // BFS 佇列
        q.push(source);                 // 起點加入 queue
        visited[source] = true;        // 標記起點已拜訪

        while (!q.empty()) {           // 當 queue 不為空就繼續

            int node = q.front();     // 取出目前節點
            q.pop();                  // 移除 queue 前端

            if (node == destination) { // 如果找到目標
                return true;          // 直接回傳 true
            }

            for (int neighbor : graph[node]) { // 遍歷所有鄰居

                if (!visited[neighbor]) {      // 如果還沒拜訪過
                    visited[neighbor] = true;  // 標記為已拜訪
                    q.push(neighbor);         // 加入 queue 繼續搜尋
                }
            }
        }

        return false;  // BFS 結束仍沒找到 destination → 不可達
    }
};