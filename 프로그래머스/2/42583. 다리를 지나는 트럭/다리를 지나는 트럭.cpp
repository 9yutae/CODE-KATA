#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> waiting;
    for(const auto& w:truck_weights) waiting.push(w);
    
    queue<int> on_bridge;
    int total_weight = 0;
    int time = 0;
    while(++time) {
        if(on_bridge.size() == bridge_length) {
            total_weight -= on_bridge.front();
            on_bridge.pop();
        }
        
        if(total_weight + waiting.front() <= weight) {
            total_weight += waiting.front();        
            on_bridge.push(waiting.front());
            waiting.pop();
        }
        else {
            on_bridge.push(0);
        }
        
        if(waiting.size() == 0) {
            time += bridge_length;
            break;
        }
    }
    
    return time;
}