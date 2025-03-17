#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 1;
    bool flag = true;
    for(long long i=k; i<=d; i+=k) {
        if(sqrt(2)*i <= d) answer++;
        else flag = false;
        
        if(flag) {
            answer += (2*i/k);
        }
        else {
            long long dist = d;
            long long j = sqrt(dist*dist - i*i) / (long long) k;
            answer += 2*(j+1);
        }
    }
    
    return answer;
}