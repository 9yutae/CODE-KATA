#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> pq;
    
    for(int i=0;i<k && i<score.size();i++) {
        pq.push(-score[i]);
        answer.emplace_back(-pq.top());
    }
    
    for(int i=k;i<score.size();i++) {
        if(score[i] > -pq.top()) {
            pq.pop();
            pq.push(-score[i]);
        }
        answer.emplace_back(-pq.top());
    }
    
    return answer;
}