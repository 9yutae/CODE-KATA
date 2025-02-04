#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> que;
    for(auto w:progresses) que.push(w);
    
    map<int, int> release;
    int index = 0, date = 0;
    while(!que.empty()) {
        int progress = que.front();
        que.pop();
        
        progress += (speeds[index] * date);
        while(progress < 100) {
            progress += speeds[index];
            date++;
        }
        release[date]++;
        index++;
    }
    
    vector<int> answer;
    for(const auto& w:release)
        answer.push_back(w.second);
    
    return answer;
}