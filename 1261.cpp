
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

class FindElements {

private:
    TreeNode* root;

    void FindElementsInner(TreeNode* root, int val){
        if(root){
            root->val = val;
            FindElementsInner(root->left, 2 * val + 1);
            FindElementsInner(root->right, 2 * val + 2);
        }
    }

    bool findInner(TreeNode* root, int target){
        if(root){
            if(root->val == target)
                return true;
            else{
                return findInner(root->left, target) || findInner(root->right, target);
            }
            
        }
        else
            return false;
    }

public:
    FindElements(TreeNode* root) {
        FindElementsInner(root, 0);
        this->root = root;
    }

    
    bool find(int target) {
        return findInner(root, target);
    }
};
