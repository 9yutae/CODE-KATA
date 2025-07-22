#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    queue<int> q;
    int totalCount = 0;
    
    for (int i = 0 ; i < players.size() ; i++) {
        while (!q.empty() && i - q.front() >= k) {
            q.pop();
        }
        
        while (players[i] >= (q.size() + 1) * m) {
            totalCount++;
            q.push(i);
        }
        
    }
    
    return totalCount;
}
