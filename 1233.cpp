
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>


using namespace std;

struct Node{
    unordered_map<string, Node*>  um;
    bool flag;
    Node(){
        flag = false;
    }
};

class Solution {
public:

    void insert(Node* root, string& folder){
        // cout << folder << endl;
        Node* cur = root;
        string temp;
        int n = folder.size();
        for(int i = 1; i <= n; i++){
            if(i == n || folder[i] == '/'){
               if(cur->um.count(temp)){
                    cur = cur->um[temp];
               }
               else{
                    Node* newNode = new Node();
                    cur->um[temp] = newNode;
                    cur = newNode;
               }
               temp.clear();
            }
            else{
                temp.push_back(folder[i]);
            }
        }
        cur->flag = true;
    }

    bool query(Node* root, string& folder){

        Node* cur = root;
        int n = folder.size();
        string temp;
        for(int i = 1; i <= n; i++){
            if(i == n || folder[i] == '/'){
                // cout << temp << endl;
                // cout << cur->um.count(temp) << endl;
                cur = cur->um[temp];
                if(cur->flag && i < n)
                    return false;
                temp.clear();
            }
            else{
                temp.push_back(folder[i]);
            } 
        }
        
        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {

        Node* root = new Node();
        for(int i = 0; i < folder.size(); i++){
            insert(root, folder[i]);
        }

        // string str = "/c/d/e";
        // cout << query(root, str);
        vector<string> ret;
        for(int i = 0; i < folder.size(); i++){
            if(query(root, folder[i]))
                ret.push_back(folder[i]);
            
        }

        return ret;
    }

};

int main(){
    vector<string> vec = {"/a","/a/b/c","/a/b/d"};
    Solution sol;
    auto ret = sol.removeSubfolders(vec);
 
    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << ' ';
}