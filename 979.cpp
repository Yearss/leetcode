
#include <vector>
#include <unordered_map>
#include <string> 

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
    
    pair<int, int> distributeCoinsInner(TreeNode* root){

        if(root == nullptr){
            return {0, 0};
        }

        auto leftRet = distributeCoinsInner(root->left);
        auto rightRet = distributeCoinsInner(root->right);

        int ret1 = leftRet.first + rightRet.first + abs(leftRet.second) + abs(rightRet.second) ;
        int ret2 = leftRet.second + rightRet.second + root->val - 1;

        return {ret1, ret2};

    }

public:
    int distributeCoins(TreeNode* root) {

        auto ret = distributeCoinsInner(root);

        return ret.first;


        
    }
};