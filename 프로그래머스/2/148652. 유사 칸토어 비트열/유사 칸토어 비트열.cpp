#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l-1; i < r; i++) {
        long long idx = i;
        for (int j=0;j<n;j++) {
            if (idx % 5 == 2) break;
            else if (idx / 5 == 0) {
                answer++;
                break;
            }
            idx /= 5;
        }
    }
    
    return answer;
}