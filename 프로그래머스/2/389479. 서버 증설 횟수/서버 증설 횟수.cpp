#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> runningServers(24 + k, 0), newServer(24 + k, 0);
    int idx = k;
    
    for (const auto& player : players) {
        runningServers[idx] = max(runningServers[idx - 1] - newServer[idx - k], 0);
        int tmp = max((player - runningServers[idx] * m) / m, 0);

        if (tmp > 0) {
            runningServers[idx] += tmp;
            newServer[idx] += tmp;
        }
        
        idx++;
    }
    
    int totalCount = 0;
    for (const auto& w : newServer)
        totalCount += w;
    
    return totalCount;
}
