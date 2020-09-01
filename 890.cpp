

#include <vector>
#include <string>


using namespace std;

class Solution {

private:
    bool checkPattern(string& word, string& pattern){

        int N = word.size();
        vector<int> index(300); // p(x) -> c
        vector<int> antiIndex(300); // g(c) -> x 

        for(int i = 0; i < N; i++){
            auto pos = pattern[i];
            if(index[pos] > 0){
                if(index[pos] != word[i])
                    return false;
            }
            else{
                if(antiIndex[word[i]] > 0)
                    return false;
                
                index[pos] = word[i];
                antiIndex[word[i]] = pos;
            }
                
        }
        
        return true;

    }    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> ret;
        for(int i = 0; i < words.size(); i++){
            if(checkPattern(words[i], pattern))
                ret.push_back(words[i]);
        }    

        return ret;
    }
};