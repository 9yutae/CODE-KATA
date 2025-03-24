#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long> weightCounts;
    
    for (int w : weights) {
        weightCounts[w]++;
    }
    
    vector<pair<int, int>> ratios = {
        {2, 3},
        {1, 2},
        {3, 4}
    };
    
    for (const auto& entry : weightCounts) {
        long long count = entry.second;
        if (count >= 2) {
            answer += (count * (count - 1)) / 2;
        }
    }
    
    for (const auto& [w, cnt] : weightCounts) {
        for (auto [a, b] : ratios) {
            long long base = (long long) w * a;
            if (base % b != 0) continue;
            
            int other = base / b;            
            if (weightCounts.find(other) != weightCounts.end()) {
                answer += (cnt * weightCounts[other]);   
            }
        }
    }
    
    return answer;
}

