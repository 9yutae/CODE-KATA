#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    for(const auto& w:number) answer += (int)(w - '0');
    
    return answer%9;
}