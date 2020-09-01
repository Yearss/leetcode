
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
    void inOrder(vector<int>& vec, TreeNode* root){
        if(root){
            inOrder(vec, root->left);
            vec.push_back(root->val);
            inOrder(vec, root->right);
        }
    }

    TreeNode* buildWithBalance(vector<int>& vec){

        int N = vec.size();
        if(N == 0)
            return nullptr;
        else {
            int mid = N / 2;
            auto root = new TreeNode(vec[mid]);
            vector<int> leftVec(vec.begin(), vec.begin() + mid);
            vector<int> rightVec(vec.begin() + mid + 1, vec.end());
            root->left = buildWithBalance(leftVec);
            root->right = buildWithBalance(rightVec);

            return root;
        }

    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> vec;
        inOrder(vec, root);
        return buildWithBalance(vec);

    }
};