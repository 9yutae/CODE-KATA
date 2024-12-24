#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    for(auto w:included) {
        if(w) answer += a;
        a += d;
    }
    
    return answer;
}