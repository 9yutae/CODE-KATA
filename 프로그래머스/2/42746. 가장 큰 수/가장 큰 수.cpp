#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int lhs, int rhs) {
    int _lhs = lhs, _rhs = rhs;
    if(_lhs < 10) _lhs = lhs * 1111;
    else if(_lhs < 100) _lhs = lhs * 101;
    else if(_lhs < 1000) _lhs = lhs * 10 + lhs / 100;
    
    if(_rhs < 10) _rhs = rhs * 1111;
    else if(_rhs < 100) _rhs = rhs * 101;
    else if(_rhs < 1000) _rhs = rhs * 10 + rhs / 100;
    
    return _lhs > _rhs;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    for(auto& w:numbers) {
        answer.append(to_string(w));
    }
    
    if(answer[0] == '0') return "0";
    return answer;
}
