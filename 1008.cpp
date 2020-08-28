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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int N = preorder.size();
        if (N == 0)
            return nullptr;
        else if (N == 1)
            return new TreeNode(preorder[0]);
        else{
            // 第一个大于root值的下标
            int pos = N;
            for(int i = 1; i < N; i++){
                if(preorder[i] > preorder[0]){
                    pos = i;
                    break;
                }
                   
            }
            vector<int> leftNums(preorder.begin() + 1, preorder.begin() + pos);
            vector<int> rightNums(preorder.begin() + pos, preorder.end());
            auto left = bstFromPreorder(leftNums);
            auto right = bstFromPreorder(rightNums);

            return new TreeNode(preorder[0], left, right);
        }
        


    }
};