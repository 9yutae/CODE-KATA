#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long i = 1;
    bool flag = false;
    
    while(i*i <= n) {
        if(i*i == n) flag = true;
        i++;
    }
    
    return flag ? i*i : -1;
}