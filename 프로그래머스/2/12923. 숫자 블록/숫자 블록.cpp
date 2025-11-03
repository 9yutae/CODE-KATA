#include <string>
#include <vector>

using namespace std;

static const int LIMIT = 10000000;

int greatestDivisor(long long n) {
    if (n == 1) return 0;
    int best = 1;

    for (long long i = 2 ; i*i <= n ; i++) {
        if (n%i != 0) continue;
        
        long long pairVal = n / i;
        
        if (pairVal <= LIMIT) return static_cast<int>(pairVal);
        
        if (i <= LIMIT && i > best) best = static_cast<int>(i);
    }
    
    return best;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer((end - begin + 1), 0);
    for (long long i = begin ; i <= end ; i++) {
        answer[i - begin] = greatestDivisor(i);
    }
    
    return answer;
}