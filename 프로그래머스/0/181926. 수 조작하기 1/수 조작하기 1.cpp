#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    for(const auto &w:control) {
        switch(w) {
            case 'w':
                answer += 1;
                break;
            case 's':
                answer -= 1;
                break;
            case 'd':
                answer += 10;
                break;
            case 'a':
                answer -= 10;
                break;
        }    
    }
    
    return answer;
}