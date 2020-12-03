
#include <iostream>
#include <vector>


using namespace std;


string solve(string& str){

    int start = -1;
    int n = str.size();
    string ret;
    char a, b, c;
    for(int i = 0; i < n; i++){


        if(i >= 2){
            if(str[i] == c && c == b){
                continue;
            }
        }
        
        if(i >= 3){
            if(str[i] == c && b == a)
                continue;
        }
       
        a = b;
        b = c;
        c = str[i];
        ret.push_back(str[i]);

        
    }

    return ret;

}



int main(){

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }

}