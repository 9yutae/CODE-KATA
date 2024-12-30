#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a%b);
}

vector<int> solution(int n, int m) {
    int gcd = GCD(n,m);
    return {gcd, n*m/gcd};
}