
#include <vector>
#include <string>
#include <set>

using namespace std;


class Node{
public:
    Node* child[26];
    set<string> indexs;
    Node(){
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};


class Solution {
private:

    Node* buildTrie(vector<string>& products){

        Node* root = new Node();
        for(int i = 0; i < products.size(); i++){
            Node* temp = root;
            for(int j = 0; j < products[i].size(); j++){
                char c = products[i][j];
                if(temp->child[c - 'a'] == nullptr){
                    temp->child[c - 'a']= new Node();
                }
                temp = temp->child[c - 'a'];
                temp->indexs.insert(products[i]);
            }
        }

        return root;

    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ret;

        Node* root = buildTrie(products);
        Node* temp = root;
        for(int i = 0; i < searchWord.size(); i++){
           
            temp = temp->child[searchWord[i] - 'a'];
            
            vector<string> vec;
            if(temp == nullptr){
                for(int j = i; j < searchWord.size(); j++)
                    ret.push_back(vec);
                break;
            }
                

            int cnt = 0;
            for(auto iter = temp->indexs.begin(); iter != temp->indexs.end() && cnt < 3; iter++, cnt++){
                vec.push_back(*iter);
            }
            ret.push_back(vec);
        }

        return ret;

    }
};