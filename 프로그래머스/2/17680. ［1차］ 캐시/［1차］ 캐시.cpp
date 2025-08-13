#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return 5 * static_cast<int>(cities.size());
    
    list<string> li;
    unordered_map<string, list<string>::iterator> cache;
    
    int executeTime = 0;
    for(string& city : cities) {
        for(char& ch : city) ch = tolower(ch);
        
        if (cache.find(city) == cache.end()) {
            if (li.size() == cacheSize) {
                string last = li.back();
                li.pop_back();
                
                cache.erase(last);
            }
            
            executeTime += 5;
        }
        else {
            li.erase(cache[city]);
            executeTime++;
        }
        
        li.push_front(city);
        cache[city] = li.begin();
    }
    
    return executeTime;
}