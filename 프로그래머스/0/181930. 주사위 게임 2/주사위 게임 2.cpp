#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = a+b+c;
    
    if(a==b) {
        answer *= (2*a*a + c*c);
        if(b==c) answer *= 3*a*a*a;
    }
    else if(b==c || a==c) answer *= (a*a + b*b + c*c);
    
    return answer;
}