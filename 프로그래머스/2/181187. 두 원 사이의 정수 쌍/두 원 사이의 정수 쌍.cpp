#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(long long x=1; x<=r2; x++) {
        long long outerY = (long long)sqrt((long long)r2*r2 - x*x);
        long long innerY = 0;
        
        if (x < r1) {
            innerY = ceil(sqrt((long long)r1*r1 - x*x));
        }
        
        answer += 4*(outerY - innerY + 1);
    }
    
    return answer;
}