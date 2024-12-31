#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long rtrinary = 0;
    
    while(n) {
        rtrinary *= 10;
        rtrinary += n%3;
        n /= 3;
    }
    
    int idx = 0;
    while(rtrinary) {
        answer += (pow(3, idx++) * (rtrinary%10));
        rtrinary /= 10;
    }
    
    return answer;
}