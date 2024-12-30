#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    for(int i=0;i<my_string.size()/m;i++) {
        answer += my_string[m*i + c-1];
    }
    
    return answer;
}