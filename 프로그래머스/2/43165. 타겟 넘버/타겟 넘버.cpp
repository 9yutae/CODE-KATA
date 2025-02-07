#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    queue<int> que;
    que.push(0);
    
    for(const auto& w:numbers) {
        int n = que.size();
        
        for(int i=0;i<n;i++) {
            int prev = que.front();
            que.pop();
            
            que.push(prev + w);
            que.push(prev - w);
        }
    }
    
    int answer = 0;
    while(!que.empty()) {
        if(que.front() == target) answer++;
        que.pop();
    }
    
    return answer;
}