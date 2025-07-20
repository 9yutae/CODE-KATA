#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> ID;
    int idx = 0;
    for (const auto& w : friends) {
        ID.insert({w, idx++});
    }
    
    vector<vector<int>> giftTable(friends.size(), vector<int>(friends.size(), 0));
    for (const auto& str : gifts) {
        stringstream ss(str);
        string from, to;
        ss >> from >> to;
        
        giftTable[ID[from]][ID[from]]++;
        giftTable[ID[to]][ID[to]]--;
        giftTable[ID[from]][ID[to]]++;
    }
    
    vector<int> nextMonth(friends.size(), 0);
    for (int i = 0 ; i < friends.size() ; i++) {
        for (int j = i + 1 ; j < friends.size() ; j++) {
            if (giftTable[i][j] > giftTable[j][i]) nextMonth[i]++;
            else if (giftTable[i][j] < giftTable[j][i]) nextMonth[j]++;
            else if (giftTable[i][i] > giftTable[j][j]) nextMonth[i]++;
            else if (giftTable[i][i] < giftTable[j][j]) nextMonth[j]++;
        }
    }
    
    return *max_element(nextMonth.begin(), nextMonth.end());
}