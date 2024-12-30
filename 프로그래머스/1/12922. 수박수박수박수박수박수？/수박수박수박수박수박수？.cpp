#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    bool flag = true;
    
    while(n--) {
        answer += flag ? "수" : "박";
        flag = flag ? false : true;
    }
    
    return answer;
}