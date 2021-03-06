#include <vector>
#include <unordered_map>
#include <string> 

using namespace std;

class Solution {

private:
    unordered_map<string, string> long2short;
    unordered_map<string, string> short2long;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if(long2short.count(longUrl))
            return long2short[longUrl];
        else{
            int N = long2short.size();
            string shortUrl = "http://tinyurl.com/";
            shortUrl.append(to_string(N));
            long2short[longUrl] = shortUrl;
            short2long[shortUrl] = longUrl;
            return shortUrl;
        }
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};