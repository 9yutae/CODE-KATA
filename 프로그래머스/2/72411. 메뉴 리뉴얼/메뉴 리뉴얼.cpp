#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    map<int, set<string>> lengthMap;
    map<string, int> stringCounts;
    for (auto& order : orders) {
        sort(order.begin(), order.end());
        
        int n = order.size();
        for (int mask = 0 ; mask < (1 << n) ; mask++) {
            string menu = "";
            for (int i = 0 ; i < n ; i++) {
                if (mask & (1 << i))
                    menu += order[i];
            }
            
            if (menu.size() > 1) {
                lengthMap[menu.size()].insert(menu);
                stringCounts[menu]++;
            }
        }
    }
    
    vector<string> answer;
    for (const int& i : course) {
        vector<string> maxKeys;
        int maxFrequency = 2;
        
        for (const string& menu : lengthMap[i]) {
            if (stringCounts[menu] > maxFrequency) {
                maxFrequency = stringCounts[menu];
                maxKeys.clear();
                maxKeys.emplace_back(menu);
            }
            else if (stringCounts[menu] == maxFrequency) {
                maxKeys.emplace_back(menu);
            }
        }
        
        for (const string& menu : maxKeys) {
            answer.emplace_back(menu);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}