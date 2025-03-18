#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey) {
        int remainder = storey % 10;
        int nextDigit = (storey / 10) % 10;
        
        if(remainder > 5 || (remainder == 5 && nextDigit >= 5)) {
            answer += (10 - remainder);
            storey += 10;
        }
        else {
            answer += remainder;
        }

        storey /= 10;
    }
    return answer;
}