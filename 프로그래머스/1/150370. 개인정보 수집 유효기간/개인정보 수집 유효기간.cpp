#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int term[26] = { 0, };
    for(const auto& w:terms) term[w[0]-'A'] = stoi(w.substr(2));
    
    int tyear = stoi(today.substr(0, 4));
    int tmonth = stoi(today.substr(5, 2));
    int tday = stoi(today.substr(8, 2));
    
    vector<int> answer;
    int idx = 1;
    for(const auto& w:privacies) {
        int expiration = term[w[11]-'A'];
        int year = stoi(w.substr(0, 4));
        int month = stoi(w.substr(5, 2));
        int day = stoi(w.substr(8, 2));
        
        if(expiration%12 + month > 12) {
            year++;
            month -= 12;
        }
        year += expiration/12;
        month += expiration%12;
        
        if(day == 1) {
            if(month == 1) month = 12;
            else month--;
            day = 28;
        }
        else day--;
        
        if(tyear > year) answer.push_back(idx);
        else if(tyear == year && tmonth > month) answer.push_back(idx);
        else if(tyear == year && tmonth == month && tday > day) answer.push_back(idx);
        idx++;
    }

    return answer;
}