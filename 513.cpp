
#include <vector>
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
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);

        int ret = root->val;
        bool memory = false;
        while(!que.empty()){

            auto node = que.front();
            que.pop();

            if(memory){
                ret = node->val;
                memory = false;
            }

            if(node == nullptr && que.empty()){
                break;
            }
            else if(node == nullptr){
                que.push(nullptr);
                memory = true;
            }
            else{
                if(node->left != nullptr)
                    que.push(node->left);
                if(node->right != nullptr)
                    que.push(node->right);
            }
        
        }

        return ret;
        
    }
};