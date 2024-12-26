#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    
    for(const auto& w:queries) {
        string str = "";
        for(int i=w[1];i>=w[0];i--) str += answer[i];
        answer.replace(w[0], w[1] - w[0] + 1, str);
    }
    
    return answer;
}