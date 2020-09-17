#include <vector>
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
        int M = pre.size();
        if(M == 0)
            return nullptr;
        else if(M == 1)
            return new TreeNode(pre[0]);
        else{
            
            int N = post.size(), p = 0;
            for(p = 0; p < N; p++){
                if(post[p] == pre[1])
                    break;
            }
            vector<int> leftPre(pre.begin() + 1, pre.begin() + 2 + p);
            vector<int> leftPost(post.begin(), post.begin() + p + 1);
            vector<int> rightPre(pre.begin() + 2 + p, pre.end());
            vector<int> rightPost(post.begin() + p + 1, post.end() - 1);

            auto left = constructFromPrePost(leftPre, leftPost);
            auto right = constructFromPrePost(rightPre, rightPost);

            return new TreeNode(pre[0], left, right);

        }
    }
};