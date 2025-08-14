#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int> pq;
    for (const auto& w : scoville) {
        pq.push(-w);
    }
    
    int answer = 0;
    while(pq.top() > -K) {        
        int leastScoville = -pq.top();
        pq.pop();
        
        if (pq.empty()) {
            answer = -1;
            break;
        }
        
        int secondLeast = -pq.top();
        pq.pop();

        pq.push(-leastScoville - 2*secondLeast);
        answer++;
    }

    return answer;
}