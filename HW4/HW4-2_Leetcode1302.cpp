#include <vector>
#include <queue>
#include <iostream>
using namespace std;
 struct TreeNode {
  int val;
  TreeNode *left;
    TreeNode *right;      TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
           // 建立一個 queue（用來做 BFS 層序走訪）
        queue<TreeNode*> q;
           // 把 root 放進 queue，從第一層開始
        q.push(root);
         // 用來存「當前層」的總和（最後會變成最深層）
        int sum = 0;
        // 當 queue 還有節點，表示還有下一層可以走
        while(!q.empty())
        {
         // 取得目前這一層的節點數量（很重要：固定這一層）
            int size=q.size();
         // 每進入一層就重新歸零（只算當層的 sum）
            sum=0;
        // 逐個處理當前這一層的所有節點
            for(int i=0 ;i<size; i++)
            {
             // 取出 queue 最前面的節點
                TreeNode* node =q.front();
             // 把這個節點從 queue 移除
                q.pop();
             // 把這個節點的值加進當前層 sum
                sum+=node->val;
             // 如果有左子節點，就丟進 queue（下一層）
                if(node->left)
                q.push(node->left);
             // 如果有右子節點，也丟進 queue（下一層）
                if(node->right)
                q.push(node->right);

            }
            
        }
        return sum;
    }
};