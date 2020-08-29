
#include <vector>
#include <queue>

using namespace std;

class Solution {


private:
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, int curNode, int target, vector<int>& path){
        if(curNode == target){
            path.push_back(curNode);
            paths.push_back(path);
            path.pop_back();
        }
        else{
            path.push_back(curNode);
            for(int i = 0; i < graph[curNode].size(); i++){
                dfs(graph, paths, graph[curNode][i], target, path);
            }
            path.pop_back();
        }
    }

    void bfs(vector<vector<int>>& graph, vector<vector<int>>& paths, int curNode, int target){

        queue<vector<int>> que;
        vector<int> path;
        path.push_back(curNode);
        que.push(path);

        while(!que.empty()){
            
            auto curPath = que.front();
            que.pop();
            auto curNode = curPath.back();
            if(curNode == target){
                paths.push_back(curPath);
            }
            else{
                for(int i = 0; i < graph[curNode].size(); i++){
                    vector<int> tmpPath(curPath.begin(), curPath.end());
                    tmpPath.push_back(graph[curNode][i]);
                    que.push(tmpPath);
                }
            }
        }

    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> paths;
        // vector<int> path;
        // dfs(graph, paths, 0, target, path);

        bfs(graph, paths, 0, N - 1);

        return paths;
    }

};