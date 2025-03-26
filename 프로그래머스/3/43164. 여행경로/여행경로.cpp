#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool usedTicket[10001];

bool dfs(vector<vector<string>>& tickets, vector<string>& answer, string current, int ticketCount) {
    answer.push_back(current);
    if (ticketCount == tickets.size()) {
        return true;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (usedTicket[i]) continue;
        if (tickets[i][0] == current) {
            usedTicket[i] = true;
            if (dfs(tickets, answer, tickets[i][1], ticketCount + 1)) {
                return true;
            }
            usedTicket[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());   
    vector<string> answer;
    dfs(tickets, answer, "ICN", 0);
    
    return answer;
}