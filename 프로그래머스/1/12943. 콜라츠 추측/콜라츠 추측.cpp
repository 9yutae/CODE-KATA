#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long curr = num;
    
    while(curr != 1 && answer <= 500) {
        if(curr%2 == 0) curr/=2;
        else curr = 3*curr + 1;
        answer++;
    }
    
    return answer < 500 ? answer : -1;
}