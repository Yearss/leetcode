
#include <vector>
#include <utility>

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

private:
    pair<int, TreeNode*> maxDepth(TreeNode* root){
        if(root == nullptr)
            return {0, root};
        else{
            auto leftRet = maxDepth(root->left);
            auto rightRet = maxDepth(root->left);

            if(leftRet.first == rightRet.first)
                return {leftRet.first + 1, root};
            else if(leftRet.first > rightRet.first)
                return {leftRet.first + 1, leftRet.second};
            else 
                return {rightRet.first + 1, rightRet.second};
        }

    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return maxDepth(root).second;
    }   
};