#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    if((a+b) % 2) return 2 * (a + b);
    else if(a % 2) return a*a + b*b;
    return abs(a - b);
}