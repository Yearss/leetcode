
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> que;
        unordered_set<int> s;
        que.push(0);

        while(!que.empty()){

            auto room = que.front();
            que.pop();
            s.insert(room);

            for(int i = 0; i < rooms[room].size(); i++){
                if(!s.count(rooms[room][i]))
                    que.push(rooms[room][i]);
            }

        }

        return s.size() == rooms.size();
        
    }
};