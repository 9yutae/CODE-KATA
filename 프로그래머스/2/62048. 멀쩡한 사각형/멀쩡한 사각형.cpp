#include <numeric>
using namespace std;

long long solution(int w,int h) {
    int GCD = gcd(w, h);
    int nw = w / GCD;
    int nh = h / GCD;
    
    long long cut = (nw + nh - 1) * GCD; 
    long long answer = (long long) w * h - cut;
    
    return answer;
}