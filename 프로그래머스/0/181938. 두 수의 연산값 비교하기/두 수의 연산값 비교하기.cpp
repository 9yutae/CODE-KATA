#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
/*

    int answer = 0;
    return answer;
*/
    return max(stoi(to_string(a) + to_string(b)), 2*a*b);
}