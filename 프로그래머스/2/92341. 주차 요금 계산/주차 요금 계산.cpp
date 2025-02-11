#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    int default_time = fees[0];
    int base_rate = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];

    map<string, pair<int, int>> time_table;
    map<string, int> times;

    for(const auto& w:records) {
        string num = w.substr(6, 4);
        int time = stoi(w.substr(0, 2)) * 60 + stoi(w.substr(3, 2));

        if(w[11] == 'I') {
            time_table[num] = { time, 1439 };
        }
        else if(w[11] == 'O') {
            time_table[num].second = time;
            times[num] += time_table[num].second - time_table[num].first;

            auto iter = time_table.find(num);
            time_table.erase(iter);
        }
    }

    for(const auto& w:time_table) {
       times[w.first] += w.second.second - w.second.first;
    } 

    map<string, int> fee;
    for(const auto& w:times) {
        fee[w.first] += base_rate;
        
        int extra = w.second - default_time;
        while(extra > 0) {
            fee[w.first] += unit_fee;
            extra -= unit_time;
        }
    }

    vector<int> answer;
    for(const auto& w:fee) {
        answer.push_back(w.second);
    }

    return answer;
}