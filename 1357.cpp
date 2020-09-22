#include <vector>
#include <iostream>

using namespace std;

class Cashier {
private:
    int curIdx;
    int n;
    int id2price[250];
    int discount;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        
        memset(id2price, 0, sizeof(prices));
        this->n = n;
        cout << "n: " << this->n << endl;
        for(int i = 0; i < products.size(); i++)
            id2price[products[i]] = prices[i];
    
        this->discount = discount;
        curIdx = 0;

    }
    
    double getBill(vector<int> product, vector<int> amount) {
        
        double s = 0;
        for(int i = 0; i < product.size(); i++){
            s += id2price[product[i]] * amount[i];
        }
        curIdx += 1;

        return curIdx % n == 0 ? s - (s * discount) / 100 : s; 
        

    }
};