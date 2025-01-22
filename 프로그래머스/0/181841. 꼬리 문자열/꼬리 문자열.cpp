#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(auto& w:str_list) {
        if(w.find(ex) == string::npos) answer.append(w);
    }
    
    return answer;
}