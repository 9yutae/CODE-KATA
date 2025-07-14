#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool Compare(const vector<int>& lhs, const vector<int>& rhs) {
    return lhs.size() < rhs.size();
}

vector<vector<int>> parseNestedArray(const string& s) {
    vector<vector<int>> parsed;
    vector<int> current;
    
    string num;
    bool inside = false;
    
    for (char ch : s) {
        if (ch == '{') {
            current.clear();
            inside = true;
        }
        else if (ch == '}') {
            if (!num.empty()) {
                current.push_back(stoi(num));
                num.clear();
            }
            if (inside) {
                parsed.push_back(current);
                current.clear();
                inside = false;
            }
        }
        else if (isdigit(ch)) {
            num += ch;
        }
        else if (ch == ',' && !num.empty()) {
            current.push_back(stoi(num));
            num.clear();
        }
    }
    
    return parsed;
}

vector<int> solution(string s) {
    vector<vector<int>> parsedIntArray = parseNestedArray(s);
    sort(parsedIntArray.begin(), parsedIntArray.end(), Compare);
    
    vector<int> answer;
    set<int> used;
    for (const auto& vec : parsedIntArray) {
        for (const auto& w : vec) {
            if (used.count(w) == 0) {
                answer.push_back(w);
                used.insert(w);
                break;
            }
        }
    }
    
    return answer;
}