#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int n = stoi(to_string(a) + to_string(b)),
        m = stoi(to_string(b) + to_string(a));
    
    answer = n > m ? n : m;
    
    // return max(stoi(to_string(a)+to_string(b)),stoi(to_string(b)+to_string(a)));
    
    return answer;
}