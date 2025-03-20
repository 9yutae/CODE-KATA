#include <string>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int minA = *min_element(arrayA.begin(), arrayA.end());
    int minB = *min_element(arrayB.begin(), arrayB.end());
    
    set<int> divisorA, divisorB;
    int tmp = max(minA, minB);
    for(int i=1; i<=sqrt(tmp); i++) {
        if(minA%i == 0) {
            divisorA.insert(i);
            divisorA.insert(minA/i);
        }
        if(minB%i == 0) {
            divisorB.insert(i);
            divisorB.insert(minB/i);
        }
    }
    
    int answer = 0;
    for(const auto& w : divisorA) {
        int idx = 0;
        bool flag = true;
        while(flag && idx < arrayA.size()) {
            if(arrayA[idx] % w != 0) flag = false;
            if(arrayB[idx] % w == 0) flag = false;
            idx++;
        }
        
        answer = flag ? max(answer, w) : answer;
    }
    
    for(const auto& w : divisorB) {
        int idx = 0;
        bool flag = true;
        while(flag && idx < arrayB.size()) {
            if(arrayA[idx] % w == 0) flag = false;
            if(arrayB[idx] % w != 0) flag = false;
            idx++;
        }
        
        answer = flag ? max(answer, w) : answer;
    }
    
    return answer;
}