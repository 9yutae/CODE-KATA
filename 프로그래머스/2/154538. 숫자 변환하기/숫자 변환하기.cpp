#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int, int>> que;
    que.push({x, 0});
    
    unordered_set<int> visited;
    visited.insert(x);
    
    while (!que.empty()) {
        int tmp = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        if (tmp == y) return cnt;
        
        vector<int> nextValues = {tmp + n, tmp * 2, tmp * 3};
        
        for (int next : nextValues) {
            if (next <= y && visited.find(next) == visited.end()) {
                visited.insert(next);
                que.push({next, cnt + 1});
            }
        }
    }
    
    return -1;
}