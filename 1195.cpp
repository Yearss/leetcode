#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>


using namespace std;

class Semaphore{
private:
    int count;
    mutex mtx;
    condition_variable cv;

public:
    Semaphore(int value = 0){
        count = value;
    }


    void setValue(int value){
        count = value;
    }

    void wait(){
        unique_lock<mutex> lck(mtx);
        if(count < 4){
            cv.wait(lck);
        }
    }

    void signal(){
        unique_lock<mutex> lck(mtx);
        count++;
        if(count == 4){
            cv.notify_all();
        }
    }
};



class FizzBuzz {
private:
    int n;
    Semaphore doingTaskNum[1000];
public:
    FizzBuzz(int n) {
        this -> n = n;
        doingTaskNum[0].setValue(4);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 1; i <= n; i++){
            doingTaskNum[i-1].wait();
            if(i % 3 == 0 && i % 5 != 0)
                printFizz();
            doingTaskNum[i-1].signal();
            doingTaskNum[i].signal();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 1; i <= n; i++){
            doingTaskNum[i-1].wait();
            if(i % 5 == 0 && i % 3 != 0)
                printBuzz();
            doingTaskNum[i-1].signal();
            doingTaskNum[i].signal();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 1; i <= n; i++){
            doingTaskNum[i-1].wait();
            if(i%3 == 0 && i%5 == 0)
                printFizzBuzz();
            doingTaskNum[i-1].signal();
            doingTaskNum[i].signal();
        }
    } 

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i++){
            doingTaskNum[i-1].wait();
            if(i % 3 != 0 && i % 5 != 0)
                printNumber(i);
            doingTaskNum[i-1].signal();
            doingTaskNum[i].signal();
        }
    }
};

void printFizzBuzz(){
    cout << "fizzbuzz" << endl;
}

void printBuzz(){
    cout << "buzz" << endl;
}

void printFizz(){
    cout << "fizz" << endl;
}

void printNumber(int x){
    cout << x << endl;
}


int main(){

    FizzBuzz fb(5);
    thread A(&FizzBuzz::buzz, &fb, printBuzz);
    thread B(&FizzBuzz::fizz, &fb, printFizz);
    thread C(&FizzBuzz::fizzbuzz, &fb, printFizzBuzz);
    thread D(&FizzBuzz::number, &fb, printNumber);

    A.join();
    B.join();
    C.join();
    D.join();

    return 0;
}