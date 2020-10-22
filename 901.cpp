
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> st;
    int idx;
public:
    StockSpanner() {
        idx = -1; 
        st.push({1e9, idx});
    }
    
    int next(int price) {
        idx ++;

        while(price >= st.top().first){
            st.pop();
        }
        
        int ret = idx - st.top().second;
        st.push({price, idx});

        return ret;
    
    }
};
