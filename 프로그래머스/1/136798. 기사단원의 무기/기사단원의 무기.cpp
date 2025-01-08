#include <string>
#include <vector>

using namespace std;

int getFactorCnt(int n, int limit, int power) {
    int cnt = 2;
    for(int i=2;i<=n/2;i++) {
        if(n%i==0) cnt++;
        if(cnt > limit) return power;
    }
    
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i=2;i<=number;i++) {
        answer += getFactorCnt(i, limit, power);
    }
    
    return answer;
}