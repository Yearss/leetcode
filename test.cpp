// main.cpp
#include <iostream>
#include <vector>
using namespace std;

class Test{
private:
    vector<int> vec;
public:
    void f(int x) {
        if(x == 200)
            return;
        f(x+1);
    }

    vodi g(){
        vec.resize(2000, -1);
    }

};

int main()
{

    auto test = Test();
    test.g();
    test.f(0);
}