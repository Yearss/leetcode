#include <vector>
#include <unordered_map>
#include <string> 
#include <queue>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);

        int level = 1, s = 0, mmax = -1e9, mmaxLevel = -1;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            if(node == nullptr){
                if(s > mmax){
                    mmax = s;
                    mmaxLevel = level;
                }
                // 重置
                s = 0;
                level += 1;
                if(!que.empty())
                    que.push(nullptr);
            }
            else{
                s += node->val;
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }

        return mmaxLevel;
 
    }
};