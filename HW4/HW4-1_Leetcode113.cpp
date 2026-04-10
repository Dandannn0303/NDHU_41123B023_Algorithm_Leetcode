#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int>path;
        dfs(root,targetSum,path,res);
        return res;
    }
    // DFS 函式：負責遞迴找路徑
    void dfs(TreeNode* root , int targetsum, vector<int>&path, vector<vector<int>> &res)
    {
           // 如果節點是空的，直接結束（防呆）
        if(!root)
        return;
        // 👉 1. 先把目前節點加入路徑
        path.push_back(root->val);

        // 👉 2. 判斷：是不是「葉節點」而且剛好符合總和
        // 葉節點 = 沒有左、右子樹
        if(!root->left&&!root->right&&root->val==targetsum)
        {
            // 找到一條正確路徑 → 存進答案
            res.push_back(path);
        }else
        {
            // 👉 3. 還沒到底，就繼續往下找
            // 同時把 targetSum 扣掉目前節點的值

            // 往左子樹找
            dfs(root->left,targetsum-root->val,path,res);

            // 往右子樹找
            dfs(root->right,targetsum-root->val,path,res);
        }
         // 👉 4. 回溯（超重要）
         // 把剛剛加入的節點拿掉，讓上一層繼續用
        path.pop_back();
    }
};
 