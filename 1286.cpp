#include <vector>
#include <string>

using namespace std;

class CombinationIterator {

private:

    vector<string> iterators;
    string tmp;
    int index;
    void CombinationIteratorInner(string& characters, int curIndex, int left){

        if(left == 0)
            iterators.push_back(tmp);
        else{
            int N = characters.size();
            if(curIndex == N)
                return;

            tmp.push_back(characters[curIndex]);
            CombinationIteratorInner(characters, curIndex+1, left - 1);
            tmp.pop_back();
            CombinationIteratorInner(characters, curIndex+1, left);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        CombinationIteratorInner(characters, 0, combinationLength);
        index = 0;
    }
    
    string next() {
        return iterators[index++];
    }
    
    bool hasNext() {
        return index < iterators.size();
    }
};
