#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> rankInt;
    map<string, int> rankName;
    for(int i=0;i<players.size();i++) {
        rankInt[i] = players[i];
        rankName[players[i]] = i;
    }
    
    for(const auto& w:callings) {
        int idx = rankName[w];
        string prev = rankInt[idx-1];
        rankName[w]--;
        rankName[prev]++;
        rankInt[idx] = prev;
        rankInt[idx-1] = w;
    }
    
    vector<string> answer;
    for(const auto& w:rankInt) {
        answer.emplace_back(w.second);
    }
    
    return answer;
}