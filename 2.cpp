
#include <vector>
#include <iostream>

using namespace std;


struct Node{
    int n;
    Node* child[2]; 
    Node(){
        n = 0;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

long countTrie(Node* root, int m, int w){

    long ret = 0;
    for(int i = 16; i >= 0; i--){
        if(root == nullptr)
            break;
        int x = (w >> i) & 1;
        int y = (m >> i) & 1;
        if(x == 0 && y == 0){
            if(root->child[1])
                ret += root->child[1]->n;
            root = root->child[0];
        }
        else if(x == 1 && y == 0){
            if(root->child[0])
                ret += root->child[0]->n;
            root = root->child[1];
        }
        else if(x == 1 && y == 1){
            root = root->child[0];
        }
        else{
            root = root->child[1];
        }
    }

    return ret;
}

void insert(Node* root, int a){
    Node* cur = root;
    for(int i = 16; i >= 0; i--){
        cur->n = cur->n + 1;
        int y = (a >> i) & 1;
        if(cur->child[y] == nullptr){
            Node* t = new Node;
            cur->child[y] = t;
        }
        cur = cur->child[y];
    }
    cur->n = cur->n + 1;
}

long solve(vector<int>& arr, int m){

    Node* root = new Node;
    for(int i = 0; i < arr.size(); i++)
        insert(root, arr[i]);
    long ret = 0;
    for(int i = 0; i < arr.size(); i++)
        ret += countTrie(root, m, arr[i]);

    return ret / 2;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    cout << solve(arr, m);
}