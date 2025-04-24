#include <string>
#include <vector>
#include <stack>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    stack<int> delivery, pickup;
    for (int i=0; i<n; i++) {
        while (deliveries[i]--) delivery.push(i+1);
        while (pickups[i]--) pickup.push(i+1);
    }
    
    long long answer = 0;
    while (!delivery.empty() && !pickup.empty()) {
        answer += 2 * max(delivery.top(), pickup.top());
        for (int i=0; i<cap; i++) {
            if (!delivery.empty()) delivery.pop();
            if (!pickup.empty()) pickup.pop();
        }
    }
    
    while (!delivery.empty()) {
        answer += 2 * delivery.top();
        for (int i=0; i<cap; i++) {
            if (!delivery.empty()) delivery.pop();
        }
    }
    
    while (!pickup.empty()) {
        answer += 2 * pickup.top();
        for (int i=0; i<cap; i++) {
            if (!pickup.empty()) pickup.pop();
        }
    }
    
    return answer;
}