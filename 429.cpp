
#include <vector>
#include <queue>


using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ret;

        if(root == nullptr)
            return ret;

        queue<Node*> que;
        que.push(root);
        que.push(nullptr);

        vector<int> tmp;
        while(!que.empty()){

            auto node = que.front();
            que.pop();

            if(node == nullptr){
                if(!que.empty())
                    que.push(nullptr);

                ret.push_back(tmp);
                tmp.clear();
            }
            else{
                tmp.push_back(node->val);
                for(int i = 0; i < node->children.size(); i++){
                    if(node->children[i] != nullptr)
                        que.push(node->children[i]);
                }
            }
        }

        return ret;
        
    }
};