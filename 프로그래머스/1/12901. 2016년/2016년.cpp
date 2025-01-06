#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer[7] = {"THU","FRI","SAT", "SUN","MON","TUE","WED"};
    int days[12] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int diff = b;
    while(a--) {
        diff += days[a];
    }
    
    return answer[diff%7];
}