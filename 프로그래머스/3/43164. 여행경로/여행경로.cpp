#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<vector<string>>& tickets, vector<string>& route, vector<bool>& used, string current, int depth) {
    route.push_back(current);
    
    if (depth == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == current) {
            used[i] = true;
            if (dfs(tickets, route, used, tickets[i][1], depth + 1)) return true;
            used[i] = false;
        }
    }
    
    route.pop_back(); // backtrack
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); // 사전순으로 정렬

    vector<string> route;
    vector<bool> used(tickets.size(), false);

    dfs(tickets, route, used, "ICN", 0);
    
    return route;
}
