
#include <vector>
#include <list>
using namespace std;


// 基础解法
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        list<int> permutation;
        for(int i = 1; i <= m; i++)
            permutation.push_back(i);

        vector<int> ret;

        // 模拟迭代
        for(int i = 0; i < queries.size(); i++){
            
            int index = 0;
            for(auto iter = permutation.begin(); iter != permutation.end(); iter++){
                if(*iter == queries[i]){
                    permutation.push_front(*iter);
                    permutation.erase(iter);
                    ret.push_back(index);
                    break;
                }
                index++;
            }
        }

        return ret;
    }

};

// 进阶解法
class Solution {

private:
    int lowbit(int x){
        return x & -x;
    }

    int sum(vector<int>& A, int y){
        
        int s = 0;
        while(y > 0){
            s += A[y];
            y = y - lowbit(y);
        }

        return s;
    }

    void update(vector<int>& A, int pos, int delta){

        int N = A.size();
        while(pos <= N){
            A[pos] += delta;
            pos = pos + lowbit(pos);
        }

    }
    

public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        //差分数列, 使用树状数组维护
        vector<int> diff(2500);
        int N = queries.size();
        for(int i = 2; i <= m; i++)
            update(diff, N + i, 1);

        //索引数组
        vector<int> index(2500);
        for(int i = 1; i <= m; i++)
            index[i] = N + i; 
  
        // 迭代queries
        vector<int> ret;
        int start = N;
        for(int i = 0; i < queries.size(); i++){

            // 查询
            int q = queries[i];
            int pos = sum(diff, index[q]);
            ret.push_back(pos);

            // 更新
            update(diff, start + 1, 1);
            update(diff, index[q], -1);
            index[q] = start;
            start --;

        }

        return ret;
    
    }

};
