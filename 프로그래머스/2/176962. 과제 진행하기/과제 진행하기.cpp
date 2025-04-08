#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Plan {
    string name;
    int startTime;
    int playTime;
};

int toMinutes(const string& time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<Plan> sortedPlans;
    for (const auto& plan : plans) {
        sortedPlans.push_back({plan[0], toMinutes(plan[1]), stoi(plan[2])});
    }
    
    sort(sortedPlans.begin(), sortedPlans.end(), [](const Plan& a, const Plan& b) {
        return a.startTime < b.startTime;
    });
    
    stack<Plan> pausedStack;
    vector<string> answer;
    int currentTime = sortedPlans[0].startTime;
    
    for (int i = 0; i < sortedPlans.size() - 1; i++) {
        Plan current = sortedPlans[i];
        Plan next = sortedPlans[i + 1];
        
        currentTime = max(currentTime, current.startTime);
        int availableTime = next.startTime - currentTime;
        
        if (availableTime >= current.playTime) {
            currentTime += current.playTime;
            answer.push_back(current.name);
            
            while (!pausedStack.empty()) {
                Plan paused = pausedStack.top();
                if (currentTime + paused.playTime <= next.startTime) {
                    currentTime += paused.playTime;
                    answer.push_back(paused.name);
                    pausedStack.pop();
                }
                else {
                    paused.playTime -= (next.startTime - currentTime);
                    pausedStack.top() = paused;
                    break;
                }
            }
        }
        else {
            current.playTime -= availableTime;
            pausedStack.push(current);
            currentTime = next.startTime;
        }
    }
    
    answer.push_back(sortedPlans.back().name);
    
    while (!pausedStack.empty()) {
        answer.push_back(pausedStack.top().name);
        pausedStack.pop();
    }
    
    return answer;
}