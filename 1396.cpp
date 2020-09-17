
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

class HashPair{
public:
    int operator()(const pair<string, string>& p) const{
        hash<string> hash_str;
        auto x = hash_str(p.first);
        auto y = hash_str(p.second);
        return x ^ y;   
    }
};

struct pair_hash{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const{
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class UndergroundSystem {
private:
    unordered_map<pair<string,string>, pair<int, int>, HashPair> stationRecord;
    unordered_map<int, pair<string, int>> custRecord;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        custRecord[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto res = custRecord[id];
        auto key = make_pair(res.first, stationName);
        auto v = stationRecord[key];

        if(stationRecord.count(key))
            stationRecord[key] = {v.first + t - res.second, v.second + 1};
        else
            stationRecord[key] = {t - res.second, 1};
        
        custRecord.erase(custRecord.find(id));
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto v = stationRecord[{startStation, endStation}];
        return v.first * 1.0 / v.second;
    }
};