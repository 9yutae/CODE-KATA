#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canConversion(const string& lhs, const string& rhs) {
    int diffCount = 0;
    for (int i=0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            diffCount++;
            if (diffCount > 1) return false;
        }
    }
    
    return diffCount == 1;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;   
    q.push({begin, 0});
    
    while(!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();
        
        if (word == target) {
            return steps;
        }
        
        for (auto iter = words.begin(); iter != words.end(); ) {
            if (canConversion(word, *iter)) {
                q.push({*iter, steps + 1});
                iter = words.erase(iter);
            }
            else {
                iter++;
            }
        }
    }
    
    return 0;
}