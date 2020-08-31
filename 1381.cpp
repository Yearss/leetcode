
#include <vector>

using namespace std;


class CustomStack {

private:
    int curIndex;
    int maxIndex;
    vector<int> s;

    int lowbit(int x){
        return x & -x;
    }

    void update(int index, int incremVal){
        while(index <= maxIndex){
            s[index] += incremVal;
            index += lowbit(index);
        }
    }

    int query(int index){

        int sum = 0;
        while(index > 0){
            sum += s[index];
            index -= lowbit(index);
        }

        return sum;
    }

public:
    CustomStack(int maxSize) {
        s.resize(2000, 0);
        maxIndex = maxSize;
        curIndex = 0;
    }
    
    void push(int x) {

        if(curIndex == maxIndex)
            return ;

        int topVal = query(curIndex);
        int incremVal = x - topVal;
        curIndex ++;
        update(curIndex, incremVal);
    }
    
    int pop() {

        if(curIndex == 0)
            return -1;

        int ret = query(curIndex); 
        int diff = ret - query(curIndex - 1);
        update(curIndex, -diff);
        curIndex --;

        return ret;
    }
    
    void increment(int k, int val) {
        

        if(curIndex > k){
            update(1, val);
            update(k + 1, -val);
        }
        else if(curIndex > 0){
            update(1, val);
        }
        
    }
};