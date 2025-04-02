#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    int round = 0;
    for (const auto& w : enemy) {
        n -= w;
        pq.push(w);
        
        if (n < 0) {
            if (k <= 0) break;
            k--;
            n += pq.top();
            pq.pop();
        }
        
        round++;
    }
    
    return round;
}